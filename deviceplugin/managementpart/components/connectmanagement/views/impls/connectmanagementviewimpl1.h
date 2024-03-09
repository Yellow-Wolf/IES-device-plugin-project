#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_VIEWS_IMPLS_CONNECTMANAGEMENTVIEWIMPL1_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_VIEWS_IMPLS_CONNECTMANAGEMENTVIEWIMPL1_H_

#include <QLabel>
#include <QAbstractButton>

#include "deviceplugin/managementpart/components/connectmanagement/views/connectmanagementview.h"


class ConnectManagementViewImpl1: public ConnectManagementView {
 public:
  explicit ConnectManagementViewImpl1(QWidget *parent = nullptr);

  void setIP(const QString &ip) override;
  void setPort(const QString &port) override;
  void setModbusID(const QString &modbus_id) override;
  void setConnectionStatus(bool connection_status) override;

 private:
  QLabel *_ip_label = nullptr;
  QLabel *_port_label = nullptr;
  QLabel *_modbus_id_label = nullptr;

  QAbstractButton *_connect_button = nullptr;
  QAbstractButton *_disconnect_button = nullptr;

  void initUI();
  void setConnections();
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_VIEWS_IMPLS_CONNECTMANAGEMENTVIEWIMPL1_H_
