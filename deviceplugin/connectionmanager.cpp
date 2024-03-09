#include "connectionmanager.h"

DevicePluginConnectionManager::DevicePluginConnectionManager(const std::shared_ptr<ModbusWrapper> &modbus_wrapper):
 _modbus_wrapper(modbus_wrapper) {

}

bool DevicePluginConnectionManager::getHWConnectionStatus() {
  bool result = false;
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->isConnected(result);
  }

  return result;
}

ErrorCode DevicePluginConnectionManager::connectHW(bool connect) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr) {
    if (connect) {
      result = _modbus_wrapper->connect();
    } else {
      result = _modbus_wrapper->disconnect();
    }
  }

  return result;
}

bool DevicePluginConnectionManager::isServerSide() {
  return false;
}

bool DevicePluginConnectionManager::getServerConnectionStatus() {
  return false;
}

ErrorCode DevicePluginConnectionManager::connectServer(bool connect) {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}
