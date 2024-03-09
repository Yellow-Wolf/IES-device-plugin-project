#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_USECASE_FACTORYUSECASE_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_USECASE_FACTORYUSECASE_H_

#include <memory>

#include <QObject>

#include <utils/services/uidgenerator.h>
#include <plugin/storages/pluginproviderstorage.h>
#include <modbuswrappers/modbuswrapperfactory.h>

#include "deviceplugin/entity/deviceentityfactory.h"
#include "deviceplugin/managementpart/components/mainmanagement/controllers/devicecontroller.h"
#include "deviceplugin/managementpart/components/channeldialog/controllers/channeleditcontroller.h"
#include "deviceplugin/managementpart/usecase/usecasefactory.h"

#include "deviceplugin/serializer.h"
#include "deviceplugin/managementpart/components/connectmanagement/controllers/connectmanagementcontroller.h"

struct FactoryUseCaseRequest {
  std::string name;
  std::string description;

  std::string ip;
  int port;
  int modbus_id;

  int poll_period = 2500;
};


struct FactoryUseCaseResponse {
  std::shared_ptr<DeviceEntity> device_entity = nullptr;
  std::shared_ptr<QWidget> device_view = nullptr;
  std::shared_ptr<PluginProvider> plugin_provider = nullptr;
  // + ещё все что надо
};


class FactoryUseCase: public QObject {
  Q_OBJECT
 public:
  explicit FactoryUseCase(const std::shared_ptr<DeviceEntityFactory> &factory,
                          const std::shared_ptr<PluginProviderStorage> &device_pack_storage,
                          const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory,
                          const std::shared_ptr<ThreadPoolBuilder> &thread_pool_builder,
                          const std::shared_ptr<UIDGenerator> &uid_generator,
                          const std::shared_ptr<DTODataParser> &dto_data_parser);

  FactoryUseCaseResponse execute(FactoryUseCaseRequest request);

 signals:
  void testValueChanged(const QString &value);

 private:
  std::shared_ptr<DeviceEntityFactory> _factory = nullptr;
  std::shared_ptr<PluginProviderStorage> _device_pack_storage = nullptr;
  std::shared_ptr<ModbusWrapperFactory> _modbus_wrapper_factory = nullptr;
  std::shared_ptr<ThreadPoolBuilder> _thread_pool_builder = nullptr;
  std::shared_ptr<UIDGenerator> _uid_generator = nullptr;

  std::shared_ptr<DTODataParser> _dto_data_parser = nullptr;

  std::vector<std::shared_ptr<DeviceController>> _test_device_controllers;
  std::vector<std::shared_ptr<ChannelEditController>> _channel_edit_controllers;
  std::vector<std::shared_ptr<ConnectManagementController>> _connect_management_controllers;

  std::shared_ptr<DeviceEntityDTO> createDTO(const std::string &file_path);

  std::shared_ptr<DevicePluginSerializer> createSerializer(const std::shared_ptr<DeviceEntity> &device_entity);

  std::shared_ptr<IDeviceEntityPoll> createDeviceTask(const std::shared_ptr<DeviceEntity> &device_entity,
                                                      const std::shared_ptr<DeviceCallbackSubscriptionStandaloneFactory> &device_cb_factory);

  std::shared_ptr<PluginCommandProvider> createCommandProvider(const std::shared_ptr<UseCaseFactory> &use_case_factory);
  std::shared_ptr<PluginViewProvider> createViewProvider(const std::shared_ptr<QWidget> &management_view,
                                                         const std::shared_ptr<ChannelEditController> &edit_channel_controller);

  std::shared_ptr<QWidget> createMVC(const std::string &name,
                                     const std::shared_ptr<UseCaseFactory> &use_case_factory,
                                     const std::shared_ptr<DeviceCallbackSubscriptionStandaloneFactory> &device_cb_factory);

  std::shared_ptr<ChannelEditController> createChannelEditMVC(const std::string &name,
                                                              const std::shared_ptr<UseCaseFactory> &use_case_factory,
                                                              const std::shared_ptr<DeviceCallbackSubscriptionFactory> &device_cb_factory);
  std::shared_ptr<ConnectManagementController> createConnectManagementController(const std::shared_ptr<
      PluginProvider> &plugin_provider, const std::shared_ptr<ModbusWrapper> &modbus_wrapper);
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_USECASE_FACTORYUSECASE_H_
