#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_PLUGINPROVIDERFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_PLUGINPROVIDERFACTORY_H_

#include <plugin/deviceplugins/pluginproviderfactory.h>
#include <utils/services/uidgenerator.h>
#include <threadpooling/threadpoolbuilder.h>
#include <modbuswrappers/modbuswrapperfactory.h>
#include <plugin/storages/pluginproviderstorage.h>

#include "deviceplugin/entity/deviceentityfactory.h"

#include "services/serializers/dtodataparser.h"

#include "deviceplugin/creationpart/usecase/factoryusecase.h"


class DevicePluginProviderFactory: public PluginProviderFactory {
 public:
  explicit DevicePluginProviderFactory(const std::shared_ptr<QWidget> &view,
                                       const std::shared_ptr<PluginProviderStorage> &device_plugin_storage,
                                       const std::shared_ptr<ThreadPoolBuilder> &thread_pool_builder,
                                       const std::shared_ptr<DTODataParser> &dto_data_parser,
                                       const std::shared_ptr<FactoryUseCase> &factory_use_case);

  PluginProviderResponse createPluginProvider(PluginProviderRequest request) override;
  ErrorCode destroyPluginProvider(const std::string &uid) override;

 private:
  std::shared_ptr<DTODataParser> _dto_data_parser = nullptr;
  std::shared_ptr<FactoryUseCase> _factory_use_case = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_PLUGINPROVIDERFACTORY_H_
