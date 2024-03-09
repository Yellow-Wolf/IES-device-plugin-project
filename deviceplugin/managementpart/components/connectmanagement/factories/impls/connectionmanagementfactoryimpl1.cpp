#include "connectionmanagementfactoryimpl1.h"

#include "deviceplugin/managementpart/components/connectmanagement/views/impls/connectmanagementviewimpl1.h"

ConnectionManagementFactoryImpl1::ConnectionManagementFactoryImpl1(const std::shared_ptr<PluginProvider> &plugin_provider,
                                                                            const std::shared_ptr<ModbusWrapper> &modbus_wrapper)
    :
  _plugin_provider(plugin_provider),
  _modbus_wrapper(modbus_wrapper) {

}

std::shared_ptr<ConnectManagementController> ConnectionManagementFactoryImpl1::createConnectManagement() {
  std::shared_ptr<ConnectManagementController> result = nullptr;

  if (_plugin_provider != nullptr) {
    auto connection_view = std::make_shared<ConnectManagementViewImpl1>();
    result = std::make_shared<ConnectManagementController>(connection_view, _modbus_wrapper, _plugin_provider);
  }

  return result;
}
