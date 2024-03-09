#include "factoryviewimpl2.h"
#include "deviceplugin/consts.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

#include <widgets/common/basic/standardpropertylabel.h>

#include <QDebug>


FactoryViewImpl2::FactoryViewImpl2(QWidget *parent) : FactoryView(parent) {
  initUI();
  setConnections();
}

QString FactoryViewImpl2::getValue() {
  return QString();
}

void FactoryViewImpl2::setValue(const QString &value) {

}

QString FactoryViewImpl2::getDeviceName() {
  return QString();
}

QString FactoryViewImpl2::getDeviceDescription() {
  return QString();
}

QString FactoryViewImpl2::getIP() {
  return QString();
}

int FactoryViewImpl2::getPort() {
  return 0;
}

int FactoryViewImpl2::getModbusID() {
  return 0;
}

int FactoryViewImpl2::getPollPeriod() {
  return 0;
}

void FactoryViewImpl2::clearWidget() {

}


void FactoryViewImpl2::initUI() {
  auto main_layout = new QVBoxLayout(this);

  auto data_layout = new QFormLayout();
  auto button_layout = new QHBoxLayout();

  auto device_name_label = new StandardPropertyLabel(tr("Имя"), this);
  auto device_desc_label = new StandardPropertyLabel(tr("Описание"), this);
  auto device_ip_label = new StandardPropertyLabel(tr("IP"), this);
  auto device_port_label = new StandardPropertyLabel(tr("Порт"), this);
  auto device_modbus_id_label = new StandardPropertyLabel(tr("MODBUS ID"), this);

  _device_name_line_edit = std::make_shared<StandardLineEdit>(this);
  _device_desc_text_edit = std::make_shared<QTextEdit>(this);
  _ip_spinbox = std::make_shared<SoftValidationSpinBox>(IP_REGEXP, this);
  _port_spinbox = std::make_shared<SoftValidationSpinBox>(PORT_REGEXP, this);
  _modbus_id_spinbox = std::make_shared<SoftValidationSpinBox>(MODBUS_ID_REGEXP, this);

  _accept_button = std::make_shared<StandardButton>(tr("Создать"),this);
  _cancel_button = std::make_shared<StandardButton>(tr("Отмена"), this);


  data_layout->addRow(device_name_label, _device_name_line_edit.get());
  data_layout->addRow(device_desc_label, _device_desc_text_edit.get());
  data_layout->addRow(device_ip_label, _ip_spinbox.get());
  data_layout->addRow(device_port_label, _port_spinbox.get());
  data_layout->addRow(device_modbus_id_label, _modbus_id_spinbox.get());

  button_layout->addStretch();
  button_layout->addWidget(_cancel_button.get());
  button_layout->addWidget(_accept_button.get());

  main_layout->addLayout(data_layout);
  main_layout->addLayout(button_layout);
}

void FactoryViewImpl2::setConnections() {
  if (_accept_button != nullptr) {
    QObject::connect(_accept_button.get(), &QAbstractButton::released,
                     this, &FactoryViewImpl2::acceptButtonClickedBridgeSlot);
  } else {
    qWarning() << "Accept button is nullptr " << __func__;
  }

  if (_cancel_button != nullptr) {
    QObject::connect(_cancel_button.get(), &QAbstractButton::released,
                     this, &FactoryViewImpl2::cancelButtonClickedBridgeSlot);
  } else {
    qWarning() << "Cancel button is nullptr " << __func__;
  }
}

void FactoryViewImpl2::acceptButtonClickedBridgeSlot() {
  QString device_name;
  QString device_desc;
  QString device_ip;
  int port = -1;
  int modbus_id = -1;
  int poll_period = 1000;

  if (_device_name_line_edit != nullptr) {
    device_name = _device_name_line_edit->text();
  } else {
    qCritical() << "Device name is nullptr " << __func__;
    return;
  }

  if (_device_desc_text_edit != nullptr) {
    device_desc = _device_desc_text_edit->toPlainText();
  } else {
    qCritical() << "Device desc is nullptr " << __func__;
    return;
  }

  if (_ip_spinbox != nullptr) {
    device_ip = _ip_spinbox->text();
  } else {
    qCritical() << "IP spinbox is nullptr " << __func__;
    return;
  }

  if (_port_spinbox != nullptr) {
    port = _port_spinbox->text().toInt();
  } else {
    qCritical() << "Port spinbox is nullptr " << __func__;
    return;
  }

  if (_modbus_id_spinbox != nullptr) {
    modbus_id = _modbus_id_spinbox->text().toInt();
  } else {
    qCritical() << "Modbus id spinbox is nullptr " << __func__;
    return;
  }

  emit createActionSignal(device_name,
                          device_desc,
                          device_ip,
                          port,
                          modbus_id,
                          poll_period);
}

void FactoryViewImpl2::cancelButtonClickedBridgeSlot() {

}
