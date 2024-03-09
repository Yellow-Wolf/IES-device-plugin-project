#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_FACTORYVIEW_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_FACTORYVIEW_H_

#include <QWidget>

class FactoryView: public QWidget {
  Q_OBJECT
 public:
  explicit FactoryView(QWidget *parent = nullptr);

  virtual void clearWidget() = 0;

  // просто, чтобы попробовать
  virtual QString getValue() = 0;
  virtual void setValue(const QString &value) = 0;

  virtual QString getDeviceName() = 0;
  virtual QString getDeviceDescription() = 0;
  virtual QString getIP() = 0;
  virtual int getPort() = 0;
  virtual int getModbusID() = 0;
  virtual int getPollPeriod() = 0;

 signals:
  void valueChanged(const QString &value);
  void createActionSignal(const QString &device_name,
                          const QString &device_desc,
                          const QString &ip,
                          int port,
                          int modbus_id,
                          int poll_period);
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_FACTORYVIEW_H_
