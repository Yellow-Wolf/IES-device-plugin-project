#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_VIEWS_CONNECTMANAGEMENTVIEW_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_VIEWS_CONNECTMANAGEMENTVIEW_H_

#include <QString>
#include <QWidget>


class ConnectManagementView: public QWidget {
  Q_OBJECT
 public:
  explicit ConnectManagementView(QWidget *parent = nullptr);

  virtual void setIP(const QString &ip) = 0;
  virtual void setPort(const QString &port) = 0;
  virtual void setModbusID(const QString &modbus_id) = 0;
  virtual void setConnectionStatus(bool connection_status) = 0;

 signals:
  void connectActionSignal();
  void disconnectActionSignal();
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_VIEWS_CONNECTMANAGEMENTVIEW_H_
