#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CONNECTIONMANAGER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CONNECTIONMANAGER_H_

#include <memory>

#include <modbuswrappers/modbuswrapper.h>
#include <plugin/deviceplugins/connectionmanager.h>


class DevicePluginConnectionManager: public ConnectionManager {
 public:
  explicit DevicePluginConnectionManager(const std::shared_ptr<ModbusWrapper> &modbus_wrapper);

  bool getHWConnectionStatus() override;
  ErrorCode connectHW(bool connect) override;
  bool isServerSide() override;
  bool getServerConnectionStatus() override;
  ErrorCode connectServer(bool connect) override;

 private:
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CONNECTIONMANAGER_H_
