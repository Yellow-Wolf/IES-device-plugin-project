#include "testplugincreationpartfactoryimpl1.h"
//#include "deviceplugin/creationpart/factory/impls/factoryfactoryimpl1.h"
#include "deviceplugin/creationpart/view/impls/factoryviewimpl2.h"
#include "deviceplugin/entity/impls/standaloneimpl1/deviceentityfactorystandaloneimpl1.h"

#include "deviceplugin/pluginproviderfactory.h"

#include "deviceplugin/consts.h"
#include "deviceplugin/services/serializers/dtoparsers/json/dtodataparserboostjsonimpl1.h"
#include "deviceplugin/managementpart/components/channeldialog/factories/impls/channeleditfactoryimpl1.h"

DevicePluginCreationPartFactoryImpl1::DevicePluginCreationPartFactoryImpl1(QObject *parent) : QObject(parent) {
  qRegisterMetaType<QVector<quint64>>("QVector<quint64>");
  qRegisterMetaType<QVector<bool> >("QVector<bool>");
  qRegisterMetaType<QVector<bool> >("QVector<quint16>");
  qRegisterMetaType<QVector<bool> >("QVector<qint16>");
  qRegisterMetaType<QVector<bool> >("QVector<quint32>");
  qRegisterMetaType<QVector<bool> >("QVector<qint32>");
}

CreationPartFactoryResponse DevicePluginCreationPartFactoryImpl1::createCreationPart(CreationPartFactoryRequest request) {
  CreationPartFactoryResponse result{};

  auto dto_data_parser = std::make_shared<DTODataParserBoostJSONImpl1>();

  auto device_plugin_storage = request.device_pack_storage;
  auto modbus_wrapper_factory = request.modbus_wrapper_factory;
  auto thread_pool_builder = request.thread_pool_builder;
  auto uid_generator = request.uid_generator;
  auto plugin_provider_factory_storage = request.plugin_provider_factory_storage;

  auto factory = std::make_shared<DeviceEntityFactoryStandaloneImpl1>();

  auto usecase = std::make_shared<FactoryUseCase>(factory,
                                                  device_plugin_storage,
                                                  modbus_wrapper_factory,
                                                  thread_pool_builder,
                                                  uid_generator,
                                                  dto_data_parser);
  auto view = std::make_shared<FactoryViewImpl2>();
  auto controller = std::make_shared<FactoryController>(view, usecase);
  _factory_controllers.push_back(controller);

  auto plugin_provider_factory = std::make_shared<DevicePluginProviderFactory>(view, device_plugin_storage, thread_pool_builder,
                                                                               dto_data_parser, usecase);

  if (plugin_provider_factory_storage != nullptr) {
    plugin_provider_factory_storage->addPluginProviderFactoryView(PLUGIN_NAME, plugin_provider_factory);
  }

//  result.factory = factory;
//  result.usecase = usecase;
//  result.controller = controller;
//  result.view = view;

  result.view = view;
  result.plugin_provider_factory = plugin_provider_factory;


  return result;
}
