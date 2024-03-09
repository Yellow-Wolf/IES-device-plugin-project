#include <iostream>

#include <QApplication>
#include <QVBoxLayout>
#include <QDebug>

#include <utils/services/uidgeneratorimpls/boost/uidgeneratorboostimpl.h>
#include <threadpooling/impls/threadpoolperiodicimplbuilder.h>
#include <modbuswrappers/storages/modbuswrapperstorageimpl1.h>
#include <modbuswrappers/modbusclientwrapper/modbusclientwrapperfactory.h>
#include <modbuswrappers/mocks/modbuswrappermockfactory.h>
#include <modbuswrappers/modbusclientwrapper/modbusclientdividablewrapperfactory.h>
#include <modbuswrappers/modbuswrappermodbusiddecorator/modbusclientmodbusiddecoratorfactory.h>
#include <modbuswrappers/modbusasyncclientwrapper/modbusasyncclientwrapperfactory.h>
#include <modbuswrappers/modbuspostponedwritewrapper/modbuspostponedwritewrapperfactory.h>
#include <plugin/storages/impls/impl1/pluginproviderfactorystorageimpl1.h>
#include <plugin/storages/impls/impl1/pluginproviderstorageimpl1.h>

#include "deviceplugin/creationpart/creationpartfactory/impl1/testplugincreationpartfactoryimpl1.h"

#include "test/tablemodel.h"
#include "test/qtmodelnotifier.h"
#include "test/channeltableview.h"
#include "test/testlanwidget.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int thread_count = 4;

  auto device_plugin_factory_storage = std::make_shared<PluginProviderFactoryStorageImpl1>();
  auto device_plugin_storage = std::make_shared<PluginProviderStorageImpl1>();

  auto modbus_wrapper_storage = std::make_shared<ModbusWrapperStorageImpl1>();
//  auto base_modbus_wrapper_factory = std::make_shared<ModbusClientWrapperFactory>();
  auto base_modbus_wrapper_factory = std::make_shared<ModbusWrapperMockFactory>();
  auto main_modbus_wrapper_factory = std::make_shared<ModbusClientModbusIDDecoratorFactory>(base_modbus_wrapper_factory, modbus_wrapper_storage);
  auto dividable_modbus_wrapper_factory = std::make_shared<ModbusClientDividableWrapperFactory>(main_modbus_wrapper_factory);
  auto async_modbus_wrapper_factory = std::make_shared<ModbusAsyncClientWrapperFactory>(dividable_modbus_wrapper_factory);
  auto postponed_modbus_wrapper_factory = std::make_shared<ModbusPostponedWriteWrapperFactory>(async_modbus_wrapper_factory);


  auto uid_generator = std::make_shared<UIDGeneratorBoostImpl>();
  auto thread_pool_builder = std::make_shared<ThreadPoolPeriodicImplBuilder>(uid_generator);

  auto thread_pool = thread_pool_builder->createBase(thread_count);
  if (thread_pool == nullptr) {
    qCritical() << "ERROR WHILE CREATING THREAD POOL " << __func__;
  }

  bool is_thread_pool_started = thread_pool->start();
  if (!is_thread_pool_started){
    qCritical() << "ERROR WHILE STARTING THREAD POOL " << __func__;
  }

  auto device_plugin_creation_part = std::make_shared<DevicePluginCreationPartFactoryImpl1>();

  auto factory_response = device_plugin_creation_part->createCreationPart({
    device_plugin_storage, async_modbus_wrapper_factory, thread_pool_builder, uid_generator, device_plugin_factory_storage
  });

  auto factory_view = factory_response.view;

  if (factory_view != nullptr) {
    factory_view->show();
  } else {
    qCritical() << "FACTORY VIEW IS NULLPTR";
  }

  auto channel_model = std::make_shared<ChannelModel>(device_plugin_storage);
  auto channel_table_model = std::make_shared<TableModel>(channel_model);
  auto nav_device_table_model_notifier = std::make_shared<QtModelNotifier>(channel_table_model);
  device_plugin_storage->addDimChangeNotifier(nav_device_table_model_notifier);

  auto table_view = new ChannelTableView(channel_model);

  table_view->setModel(channel_table_model.get());

  table_view->show();

  auto test_lan_widget = new TestLanWidget(device_plugin_storage, nullptr);
  test_lan_widget->show();

  return app.exec();
}
