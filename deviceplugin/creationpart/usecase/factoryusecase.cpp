#include "factoryusecase.h"

#include <plugin/deviceplugins/commandproviders/commandproviderimpl1.h>
#include <plugin/deviceplugins/serviceprovider.h>

#include <modbuswrappers/modbuspostponedwritewrapper/modbuspostponedwritewrapperfactory.h>

#include "deviceplugin/managementpart/components/mainmanagement/views/impls/deviceviewimpl1.h"
#include "deviceplugin/managementpart/components/mainmanagement/controllers/devicecontroller.h"
#include "deviceplugin/dataprovider.h"
#include "deviceplugin/connectionmanager.h"
#include "deviceplugin/commandproviderfactory.h"
#include "deviceplugin/viewprovider.h"

#include "deviceplugin/services/callbacksubscriptions/devicecallbacksubscriptionfactory.h"
#include "deviceplugin/services/callbacksubscriptions/impls/standaloneimpl/devicecallbacksubscriptionstandalonefactory.h"
#include "deviceplugin/services/callbacksubscriptions/deviceentitypoll.h"

#include "deviceplugin/managementpart/components/channeldialog/views/channeleditdialog.h"
#include "deviceplugin/managementpart/components/channeldialog/views/impls/channeleditdialogimpl1.h"

#include "deviceplugin/services/serializers/dtoloaders/filesystem/dtodataloaderfilesystemimpl1.h"
#include "deviceplugin/services/serializers/dtoparsers/json/dtodataparserboostjsonimpl1.h"
#include "deviceplugin/pluginserviceprovider.h"
#include "deviceplugin/managementpart/components/channeldialog/factories/impls/channeleditfactoryimpl1.h"
#include "deviceplugin/viewproviderfactory.h"
#include "deviceplugin/managementpart/components/connectmanagement/factories/impls/connectionmanagementfactoryimpl1.h"
#include "deviceplugin/managementpart/components/connectmanagement/controllers/connectmanagementcontroller.h"

#include <QDebug>

static const int HOLDING_REGS_COUNT = 83;
static const int INPUT_REGS_COUNT = 15;


FactoryUseCase::FactoryUseCase(const std::shared_ptr<DeviceEntityFactory> &factory,
                               const std::shared_ptr<PluginProviderStorage> &device_pack_storage,
                               const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory,
                               const std::shared_ptr<ThreadPoolBuilder> &thread_pool_builder,
                               const std::shared_ptr<UIDGenerator> &uid_generator,
                               const std::shared_ptr<DTODataParser> &dto_data_parser):
                               _factory(factory),
                               _device_pack_storage(device_pack_storage),
                               _modbus_wrapper_factory(modbus_wrapper_factory),
                               _thread_pool_builder(thread_pool_builder),
                               _uid_generator(uid_generator),
                               _dto_data_parser(dto_data_parser) {

}

FactoryUseCaseResponse FactoryUseCase::execute(FactoryUseCaseRequest request) {
  FactoryUseCaseResponse response{};

  auto name = request.name;
  auto description = request.description;

  auto poll_period = request.poll_period;
  auto ip = request.ip;
  auto port = request.port;
  auto modbus_id = request.modbus_id;

  auto holding_regs_count = HOLDING_REGS_COUNT;
  auto input_regs_count = INPUT_REGS_COUNT;

  std::shared_ptr<DeviceEntity> test_device_entity = nullptr;
  std::shared_ptr<QWidget> test_device_view = nullptr;
  std::shared_ptr<QWidget> channel_edit_view = nullptr;
  std::shared_ptr<QWidget> connect_management_view = nullptr;
  std::shared_ptr<QWidget> monitoring_view = nullptr;
  std::shared_ptr<PluginProvider> plugin_provider = nullptr;
  if (_factory != nullptr && _uid_generator != nullptr &&
    _device_pack_storage != nullptr && _modbus_wrapper_factory != nullptr
    && _thread_pool_builder != nullptr) {

    auto cps_device_cb_factory = std::make_shared<DeviceCallbackSubscriptionStandaloneFactory>();

    // TODO: Дописать
    auto modbus_wrapper = _modbus_wrapper_factory->createModbusWrapper(ip, port, modbus_id, holding_regs_count, input_regs_count);
    // TODO: потом исправить

    // ПОТОМ УБРАТЬ!
    std::string dto_file_path = "";
    auto dto = createDTO(dto_file_path);
    if (dto != nullptr) {
      dto->ip = ip;
      dto->port = port;
      dto->modbus_id = modbus_id;
      dto->poll_period = poll_period;

      test_device_entity = _factory->createDeviceEntity(modbus_wrapper, dto);

      auto uid = _uid_generator->generateUIDString();

      auto background_task = createDeviceTask(test_device_entity, cps_device_cb_factory);
      auto use_case_factory = std::make_shared<UseCaseFactory>(test_device_entity, background_task);

      _thread_pool_builder->addTask(background_task, uid, poll_period);

      test_device_view = createMVC(name, use_case_factory, cps_device_cb_factory);
      auto channel_edit_controller = createChannelEditMVC(name, use_case_factory, cps_device_cb_factory);
      if (channel_edit_controller == nullptr) {
        return response;
      }
      channel_edit_view = channel_edit_controller->getView();


      auto get_channel_count_use_case = use_case_factory->createGetChannelsCountUseCase();
      auto get_channel_delay_use_case = use_case_factory->createGetChannelDelayUseCase();

      auto data_provider = std::make_shared<DevicePluginDataProvider>(test_device_entity);
      auto connection_manager = std::make_shared<DevicePluginConnectionManager>(modbus_wrapper);
      auto command_provider = createCommandProvider(use_case_factory);
      // TODO: добавить потом проверки на nullptr
      auto view_provider = createViewProvider(test_device_view, channel_edit_controller);

      auto serializer = createSerializer(test_device_entity);
      auto service_provider = std::make_shared<DevicePluginServiceProvider>(background_task);


      data_provider->setDeviceName(name);
      data_provider->setDeviceDescription(description);

//
//    auto string = serializer->serialize();
//    qDebug() << "SERIALIZED!!!!\t\t\t\t" << string.c_str() << "\t\t\t\t";

      plugin_provider = std::make_shared<PluginProvider>(data_provider,
                                                         connection_manager,
                                                         command_provider,
                                                         view_provider,
                                                         serializer,
                                                         service_provider);

      auto connect_management_controller = createConnectManagementController(plugin_provider, modbus_wrapper);
      if (connect_management_controller != nullptr) {
        connect_management_view = connect_management_controller->getView();
      }

      view_provider->setConnectionWidget(connect_management_view);

      _device_pack_storage->addDevice(uid, plugin_provider);
    }
  }

  // TODO: УБрать потом!!
//  auto command_response = plugin_provider->executeCommandByKey({"get_positive_amperage", false});
//  auto command_response_1 = plugin_provider->executeCommandByKey({"set_cps_status", true});
//  qDebug() << "Command RESPONSE is " << command_response.response;




  response.plugin_provider = plugin_provider;
  response.device_entity = test_device_entity;
  response.device_view = test_device_view;
  return response;
}

std::shared_ptr<DevicePluginSerializer> FactoryUseCase::createSerializer(const std::shared_ptr<DeviceEntity> &device_entity) {
  std::shared_ptr<DevicePluginSerializer> result = nullptr;

  if (_dto_data_parser != nullptr) {
    result = std::make_shared<DevicePluginSerializer>(device_entity, _dto_data_parser);
  }

  return result;
}

std::shared_ptr<DeviceEntityDTO> FactoryUseCase::createDTO(const std::string &file_path) {
  auto dto = std::make_shared<DeviceEntityDTO>();

  dto->inner_start_period = 1000;
  dto->inner_start_width = 500;
  dto->inner_start_enabled = true;
  dto->inner_start_inverted = false;
  auto &channels = dto->channels;
  for (int i = 0; i < channels.size(); i++) {
      channels[i].channel_enabled = true;
      channels[i].channel_inverted = false;
      channels[i].channel_delay = 200 + i * 100;
      channels[i].channel_width = 100000;
      channels[i].channel_start_source = i;
  }

  return dto;
}

std::shared_ptr<IDeviceEntityPoll> FactoryUseCase::createDeviceTask(const std::shared_ptr<DeviceEntity> &device_entity,
                                                                    const std::shared_ptr<DeviceCallbackSubscriptionStandaloneFactory> &device_cb_factory) {
  // TODO: Дописать создание фоновой задачи
  std::shared_ptr<IDeviceEntityPoll> result = nullptr;

  result = std::make_shared<DeviceEntityPoll>(device_entity, device_cb_factory);
  return result;
}

std::shared_ptr<QWidget> FactoryUseCase::createMVC(const std::string &name,
                                                   const std::shared_ptr<UseCaseFactory> &use_case_factory,
                                                   const std::shared_ptr<DeviceCallbackSubscriptionStandaloneFactory> &device_cb_factory) {
  std::shared_ptr<DeviceView> device_view = nullptr;

  if (use_case_factory != nullptr) {
    auto set_channel_enabled_status_use_case = use_case_factory->createSetChannelEnabledStatusUseCase();

    device_view = std::make_shared<DeviceViewImpl1>(QString::fromStdString(name));

    // TODO: Дописать процесс создания
    auto test_device_view_controller = std::make_shared<DeviceController>(device_view,
                                                                          use_case_factory,
                                                                          device_cb_factory);

    test_device_view_controller->setConnections();

    _test_device_controllers.push_back(test_device_view_controller);


  }

  return device_view;
}

std::shared_ptr<ChannelEditController> FactoryUseCase::createChannelEditMVC(const std::string &name,
                                                                            const std::shared_ptr<UseCaseFactory> &use_case_factory,
                                                                            const std::shared_ptr<DeviceCallbackSubscriptionFactory> &device_cb_factory) {

  std::shared_ptr<ChannelEditDialog> edit_view = nullptr;
  std::shared_ptr<ChannelEditController> channel_edit_controller = nullptr;

//  if (use_case_factory != nullptr) {
//    auto get_channel_delay_use_case = use_case_factory->createGetChannelDelayUseCase();
//    auto set_channel_enabled_status_use_case = use_case_factory->createSetChannelEnabledStatusUseCase();
//
//    edit_view = std::make_shared<ChannelEditDialogImpl1>();
//    channel_edit_controller = std::make_shared<ChannelEditController>(device_cb_factory,
//                                                                      edit_view,
//                                                                      get_channel_delay_use_case,
//                                                                      set_channel_enabled_status_use_case);
//
//    _channel_edit_controllers.push_back(channel_edit_controller);
//  }

  auto channel_edit_factory = std::make_shared<ChannelEditFactoryImpl1>(device_cb_factory, use_case_factory);
  if (channel_edit_factory != nullptr) {
    channel_edit_controller = channel_edit_factory->createChannelEditDialog();
    if (channel_edit_controller != nullptr) {
      _channel_edit_controllers.push_back(channel_edit_controller);
    }
  }

  return channel_edit_controller;
}

std::shared_ptr<PluginCommandProvider> FactoryUseCase::createCommandProvider(const std::shared_ptr<UseCaseFactory> &use_case_factory) {
  std::shared_ptr<PluginCommandProvider> command_provider = nullptr;

  // TODO: потом вынести фабрику в поле класса
  auto command_provider_factory = std::make_shared<CommandProviderFactory>();
  command_provider = command_provider_factory->createCommandProvider(use_case_factory);

  return command_provider;
}


std::shared_ptr<PluginViewProvider> FactoryUseCase::createViewProvider(const std::shared_ptr<QWidget> &management_view,
                                                                       const std::shared_ptr<ChannelEditController> &edit_channel_controller) {
  std::shared_ptr<PluginViewProvider> view_provider = nullptr;

  auto view_provider_factory = std::make_shared<ViewProviderFactory>();
  view_provider = view_provider_factory->createViewProvider(management_view, edit_channel_controller);


  return view_provider;
}

std::shared_ptr<ConnectManagementController> FactoryUseCase::createConnectManagementController(const std::shared_ptr<PluginProvider> &plugin_provider,
                                                                                               const std::shared_ptr<ModbusWrapper> &modbus_wrapper) {
  std::shared_ptr<ConnectManagementController> result = nullptr;
  if (plugin_provider != nullptr) {
    auto connect_management_factory = std::make_shared<ConnectionManagementFactoryImpl1>(plugin_provider, modbus_wrapper);
    result = connect_management_factory->createConnectManagement();
  }
  return result;
}
