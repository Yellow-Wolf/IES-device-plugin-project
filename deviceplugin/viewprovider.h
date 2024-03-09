#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_VIEWPROVIDER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_VIEWPROVIDER_H_

#include <QVariant>

#include <plugin/deviceplugins/viewprovider.h>

#include "deviceplugin/managementpart/components/channeldialog/controllers/channeleditcontroller.h"

class DevicePluginViewProvider: public PluginViewProvider {
 public:
  explicit DevicePluginViewProvider(const std::shared_ptr<QWidget> &management_view,
                                    const std::shared_ptr<ChannelEditController> &edit_channel_controller);

  void setFactoryWidget(const std::shared_ptr<QWidget> &widget);
  void setManagementWidget(const std::shared_ptr<QWidget> &widget);
  void setManagementWidget(const std::shared_ptr<QWidget> &widget, const QString &key);

  std::shared_ptr<QWidget> getFactoryWidget() override;
  std::shared_ptr<QWidget> getManagementWidget() override;
  bool hasManagementWidgetByKey(const QString &key) override;
  std::shared_ptr<QWidget> getManagementWidget(const QString &key, QVariant arg = {}) override;

 private:
  std::shared_ptr<QWidget> _factory_widget = nullptr;
  std::shared_ptr<QWidget> _main_management_widget = nullptr;

  std::shared_ptr<ChannelEditController> _edit_channel_controller = nullptr;

  std::map<QString, std::shared_ptr<QWidget>> _management_widgets;


};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_VIEWPROVIDER_H_
