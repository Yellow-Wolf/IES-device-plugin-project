#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_VIEW_IMPLS_FACTORYVIEWIMPL1_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_VIEW_IMPLS_FACTORYVIEWIMPL1_H_

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QPushButton>

#include "deviceplugin/creationpart/view/factoryview.h"

#include <widgets/common/basic/softvalidationspinbox2.h>



class FactoryViewImpl1: public FactoryView {
 public:
  explicit FactoryViewImpl1(QWidget *parent = nullptr);

  void clearWidget() override;

  QString getValue() override;
  void setValue(const QString &value) override;

  QString getDeviceName() override;
  QString getDeviceDescription() override;
  QString getIP() override;
  int getPort() override;
  int getModbusID() override;
  int getPollPeriod() override;

 private:
  QLineEdit *_device_name = nullptr;
  QTextEdit *_device_description = nullptr;

  QLineEdit *_ip_line_edit = nullptr;
  QSpinBox *_port_spin_box = nullptr;
  QSpinBox *_modbus_id_spin_box = nullptr;

  QSpinBox *_poll_period = nullptr;

  QPushButton *_accept_button = nullptr;
  QPushButton *_cancel_button = nullptr;

  void initUI();

 private slots:
  void bridgeSlot();
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_VIEW_IMPLS_FACTORYVIEWIMPL1_H_
