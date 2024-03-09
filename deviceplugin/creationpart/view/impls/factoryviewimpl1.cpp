#include "factoryviewimpl1.h"

#include <QGridLayout>
#include <QFormLayout>
#include <QPushButton>

FactoryViewImpl1::FactoryViewImpl1(QWidget *parent): FactoryView(parent) {
  initUI();
}

QString FactoryViewImpl1::getValue() {
  return QString();
}

void FactoryViewImpl1::setValue(const QString &value) {

}

void FactoryViewImpl1::initUI() {
  auto main_layout = new QGridLayout(this);

  auto form_layout = new QFormLayout();

  auto device_name_label = new QLabel(tr("device name"), this);
  auto device_description_label = new QLabel(tr("device description"), this);
  auto device_ip_label = new QLabel(tr("device ip"), this);
  auto device_port_label = new QLabel(tr("device port"), this);
  auto device_modbus_id_label = new QLabel(tr("modbus id"), this);
  auto device_poll_period = new QLabel(tr("poll period"), this);

  _device_name = new QLineEdit(this);
  _device_description = new QTextEdit(this);
  _ip_line_edit = new QLineEdit(this);
  _port_spin_box = new QSpinBox(this);
  _modbus_id_spin_box = new QSpinBox(this);
  _poll_period = new QSpinBox(this);

  _accept_button = new QPushButton(tr("Accept"), this);
  _cancel_button = new QPushButton(tr("Cancel"), this);

  form_layout->addRow(device_name_label, _device_name);
  form_layout->addRow(device_description_label, _device_description);
  form_layout->addRow(device_ip_label, _ip_line_edit);
  form_layout->addRow(device_port_label, _port_spin_box);
  form_layout->addRow(device_modbus_id_label, _modbus_id_spin_box);
  form_layout->addRow(device_poll_period, _poll_period);


  main_layout->addLayout(form_layout, 0, 0, 1, 2);
  main_layout->addWidget(_cancel_button, 1, 0);
  main_layout->addWidget(_accept_button, 1, 1);


//  if (_accept_button != nullptr) {
//    QObject::connect(_accept_button, &QAbstractButton::released,
//                     this, &FactoryView::createActionSignal);
//  }
}

void FactoryViewImpl1::bridgeSlot() {
  QString t = "12";
  emit FactoryView::valueChanged(t);
//  emit createActionSignal();
}

void FactoryViewImpl1::clearWidget() {

}

QString FactoryViewImpl1::getDeviceName() {
  QString result;

  if (_device_name != nullptr) {
    result = _device_name->text();
  }

  return result;
}

QString FactoryViewImpl1::getDeviceDescription() {
  QString result;

  if (_device_description != nullptr) {
    result = _device_description->toPlainText();
  }

  return result;
}

QString FactoryViewImpl1::getIP() {
  QString result;

  if (_ip_line_edit != nullptr) {
    result = _ip_line_edit->text();
  }

  return result;;
}

int FactoryViewImpl1::getPort() {
  int result = -1;

  if (_port_spin_box != nullptr) {
    result = _port_spin_box->value();
  }

  return result;
}

int FactoryViewImpl1::getModbusID() {
  int result = -1;

  if (_modbus_id_spin_box != nullptr) {
    result = _modbus_id_spin_box->value();
  }

  return result;
}

int FactoryViewImpl1::getPollPeriod() {
  int result = -1;

  if (_poll_period != nullptr) {
    result = _poll_period->value();
  }

  return result;
}

