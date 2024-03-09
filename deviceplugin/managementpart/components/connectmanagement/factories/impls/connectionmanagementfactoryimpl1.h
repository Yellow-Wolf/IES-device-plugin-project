#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_FACTORIES_IMPLS_CONNECTIONMANAGEMENTFACTORYIMPL1_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_FACTORIES_IMPLS_CONNECTIONMANAGEMENTFACTORYIMPL1_H_

#include "deviceplugin/managementpart/components/connectmanagement/factories/connectmanagementfactory.h"


class ConnectionManagementFactoryImpl1: public ConnectManagementFactory {
 public:
  explicit ConnectionManagementFactoryImpl1(const std::shared_ptr<PluginProvider> &plugin_provider,
                                            const std::shared_ptr<ModbusWrapper> &modbus_wrapper);

  std::shared_ptr<ConnectManagementController> createConnectManagement() override;

 private:
  std::shared_ptr<PluginProvider> _plugin_provider = nullptr;
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_FACTORIES_IMPLS_CONNECTIONMANAGEMENTFACTORYIMPL1_H_
