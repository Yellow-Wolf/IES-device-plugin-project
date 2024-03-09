#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_COMMANDPROVIDERFACTORY_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_COMMANDPROVIDERFACTORY_H_

#include <memory>

#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/managementpart/usecase/usecasefactory.h"


class CommandProviderFactory {
 public:
  std::shared_ptr<PluginCommandProvider> createCommandProvider(const std::shared_ptr<UseCaseFactory> &use_case_factory);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_COMMANDPROVIDERFACTORY_H_
