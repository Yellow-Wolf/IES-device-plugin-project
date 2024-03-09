#include "connectmanagementcontroller.h"

ConnectManagementController::ConnectManagementController(const std::shared_ptr<ConnectManagementView> &connect_management_view,
                                                         const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                         const std::shared_ptr<PluginProvider> &plugin_provider,
                                                         QObject *parent):
                                                         QObject(parent),
                                                         _connect_management_view(connect_management_view),
                                                         _modbus_wrapper(modbus_wrapper),
                                                         _plugin_provider(plugin_provider) {
  setConnections();
  initView();
}

void ConnectManagementController::initView() {
  if (_modbus_wrapper != nullptr) {
    auto ip = _modbus_wrapper->getIP();
    auto port = _modbus_wrapper->getPort();
    auto modbus_id = _modbus_wrapper->getModbusID();

    if (_connect_management_view != nullptr) {
      _connect_management_view->setIP(ip.c_str());
      _connect_management_view->setPort(QString::number(port));
      _connect_management_view->setModbusID(QString::number(modbus_id));
    }
  }
}

std::shared_ptr<ConnectManagementView> ConnectManagementController::getView() {
  return _connect_management_view;
}

void ConnectManagementController::setConnections() {
  if (_connect_management_view != nullptr) {
    QObject::connect(_connect_management_view.get(), &ConnectManagementView::connectActionSignal,
                     this, &ConnectManagementController::connectActionViewSlot);
    QObject::connect(_connect_management_view.get(), &ConnectManagementView::disconnectActionSignal,
                     this, &ConnectManagementController::disconnectActionViewSlot);
  }
}

void ConnectManagementController::ipChangedModelSlot(const QString &ip) {
  if (_connect_management_view != nullptr) {
    _connect_management_view->setIP(ip);
  }
}

void ConnectManagementController::portChangedModelSlot(int port) {
  if (_connect_management_view != nullptr) {
    _connect_management_view->setPort(QString::number(port));
  }
}

void ConnectManagementController::modbusIDChangedModelSlot(int modbus_id) {
  if (_connect_management_view != nullptr) {
    _connect_management_view->setModbusID(QString::number(modbus_id));
  }
}

void ConnectManagementController::connectActionViewSlot() {
  if (_plugin_provider != nullptr) {
    _plugin_provider->connectHW(true);
  }
}

void ConnectManagementController::disconnectActionViewSlot() {
  if (_plugin_provider != nullptr) {
    _plugin_provider->connectHW(false);
  }
}
