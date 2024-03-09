#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_DATAPROVIDER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_DATAPROVIDER_H_

#include <plugin/deviceplugins/dataprovider.h>

#include "deviceplugin/entity/deviceentity.h"


class DevicePluginDataProvider: public PluginDataProvider {
 public:
  explicit DevicePluginDataProvider(const std::shared_ptr<DeviceEntity> &test_device_entity);

  std::string getPluginName() override;
  std::string getPluginDescription() override;
  std::string getPluginVersion() override;
  std::string getPluginDeveloperInfo() override;
  QIcon *getPluginIcon() override;
  std::string getDeviceName() override;
  void setDeviceName(const std::string &value) override;
  void setDeviceDescription(const std::string &value) override;
  std::string getDeviceDescription() override;
  std::string getDeviceType() override;
  std::string getDeviceFirmwareVersion() override;
  std::string getDeviceDeveloperInfo() override;
  DeviceState getDeviceState() override;

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_DATAPROVIDER_H_
