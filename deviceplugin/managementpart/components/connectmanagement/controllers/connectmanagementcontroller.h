#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_CONTROLLERS_CONNECTMANAGEMENTCONTROLLER_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_CONTROLLERS_CONNECTMANAGEMENTCONTROLLER_H_

#include <memory>

#include <QObject>

#include <modbuswrappers/modbuswrapper.h>
#include <plugin/deviceplugins/pluginprovider.h>

#include "deviceplugin/managementpart/components/connectmanagement/views/connectmanagementview.h"


class ConnectManagementController: public QObject {
  Q_OBJECT
 public:
  explicit ConnectManagementController(const std::shared_ptr<ConnectManagementView> &connect_management_view,
                                       const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                       const std::shared_ptr<PluginProvider> &plugin_provider,
                                       QObject *parent = nullptr);

  std::shared_ptr<ConnectManagementView> getView();

 private:
  std::shared_ptr<ConnectManagementView> _connect_management_view = nullptr;
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;
  std::shared_ptr<PluginProvider> _plugin_provider = nullptr;

  void setConnections();

  void initView();

 private slots:
  void ipChangedModelSlot(const QString &ip);
  void portChangedModelSlot(int port);
  void modbusIDChangedModelSlot(int modbus_id);

  void connectActionViewSlot();
  void disconnectActionViewSlot();
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CONNECTMANAGEMENT_CONTROLLERS_CONNECTMANAGEMENTCONTROLLER_H_
