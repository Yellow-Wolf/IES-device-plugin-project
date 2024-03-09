#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_TESTPLUGINSERVICEPROVIDER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_TESTPLUGINSERVICEPROVIDER_H_

#include <plugin/deviceplugins/serviceprovider.h>


class DevicePluginServiceProvider: public PluginServiceProvider {
 public:
  explicit DevicePluginServiceProvider(const std::shared_ptr<IProcessable> &background_task);

  std::shared_ptr<IProcessable> getBackgroundTask() override;
  bool hasBackgroundTaskByKey(const std::string &key) override;
  std::shared_ptr<IProcessable> getBackgroundTaskByKey(const std::string &key) override;

 private:
  std::shared_ptr<IProcessable> _background_task = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_TESTPLUGINSERVICEPROVIDER_H_
