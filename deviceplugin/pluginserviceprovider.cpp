#include "pluginserviceprovider.h"

DevicePluginServiceProvider::DevicePluginServiceProvider(const std::shared_ptr<IProcessable> &background_task):
 _background_task(background_task) {

}

std::shared_ptr<IProcessable> DevicePluginServiceProvider::getBackgroundTask() {
  return _background_task;
}

bool DevicePluginServiceProvider::hasBackgroundTaskByKey(const std::string &key) {
  return false;
}

std::shared_ptr<IProcessable> DevicePluginServiceProvider::getBackgroundTaskByKey(const std::string &key) {
  return std::shared_ptr<IProcessable>();
}
