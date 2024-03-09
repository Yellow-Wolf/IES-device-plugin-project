#include "connectmanagementviewimpl1.h"

#include <QVBoxLayout>
#include <QFormLayout>

#include <widgets/common/basic/standardpropertylabel.h>
#include <widgets/common/basic/standardbutton.h>

ConnectManagementViewImpl1::ConnectManagementViewImpl1(QWidget *parent) : ConnectManagementView(parent) {
  initUI();
  setConnections();
}

void ConnectManagementViewImpl1::initUI() {
  auto main_layout = new QVBoxLayout(this);

  auto form_layout = new QFormLayout();
  auto buttons_layout = new QHBoxLayout();

  auto ip_key_label = new StandardPropertyLabel(tr("IP"), this);
  auto port_key_label = new StandardPropertyLabel(tr("Порт"), this);
  auto modbus_id_key_label = new StandardPropertyLabel("MODBUS ID", this);

  _ip_label = new StandardPropertyLabel("", this);
  _port_label = new StandardPropertyLabel("", this);
  _modbus_id_label = new StandardPropertyLabel("", this);

  _connect_button = new StandardButton(tr("Подключиться"), this);
  _disconnect_button = new StandardButton(tr("Отключиться"), this);

  _connect_button->setEnabled(false);
  _disconnect_button->setEnabled(false);

  form_layout->addRow(ip_key_label, _ip_label);
  form_layout->addRow(port_key_label, _port_label);
  form_layout->addRow(modbus_id_key_label, _modbus_id_label);

  buttons_layout->addWidget(_connect_button);
  buttons_layout->addWidget(_disconnect_button);

  main_layout->addLayout(form_layout);
  main_layout->addLayout(buttons_layout);
}

void ConnectManagementViewImpl1::setConnections() {
  if (_connect_button != nullptr) {
    QWidget::connect(_connect_button, &QAbstractButton::released,
                     this, &ConnectManagementViewImpl1::connectActionSignal);
  }

  if (_disconnect_button != nullptr) {
    QWidget::disconnect(_disconnect_button, &QAbstractButton::released,
                     this, &ConnectManagementViewImpl1::disconnectActionSignal);
  }
}

void ConnectManagementViewImpl1::setIP(const QString &ip) {
  if (_ip_label != nullptr) {
    _ip_label->setText(ip);
  }
}

void ConnectManagementViewImpl1::setPort(const QString &port) {
  if (_port_label != nullptr) {
    _port_label->setText(port);
  }
}

void ConnectManagementViewImpl1::setModbusID(const QString &modbus_id) {
  if (_modbus_id_label != nullptr) {
    _modbus_id_label->setText(modbus_id);
  }
}

void ConnectManagementViewImpl1::setConnectionStatus(bool connection_status) {

}
