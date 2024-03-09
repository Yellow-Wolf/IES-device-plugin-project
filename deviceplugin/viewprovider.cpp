#include "viewprovider.h"

#include <QDebug>


static const QString EDIT_CHANNEL_WIDGET_NAME = "EditChannel";


DevicePluginViewProvider::DevicePluginViewProvider(const std::shared_ptr<QWidget> &management_view,
                                                   const std::shared_ptr<ChannelEditController> &edit_channel_controller):
                                                   _main_management_widget(management_view),
                                                   _edit_channel_controller(edit_channel_controller) {

}

void DevicePluginViewProvider::setFactoryWidget(const std::shared_ptr<QWidget> &widget) {
  _factory_widget = widget;
}

void DevicePluginViewProvider::setManagementWidget(const std::shared_ptr<QWidget> &widget) {
  _main_management_widget = widget;
}

void DevicePluginViewProvider::setManagementWidget(const std::shared_ptr<QWidget> &widget, const QString &key) {
  _management_widgets[key] = widget;
}

std::shared_ptr<QWidget> DevicePluginViewProvider::getFactoryWidget() {
  return _factory_widget;
}

std::shared_ptr<QWidget> DevicePluginViewProvider::getManagementWidget() {
  return _main_management_widget;
}

bool DevicePluginViewProvider::hasManagementWidgetByKey(const QString &key) {
  bool result = false;

  if (key == EDIT_CHANNEL_WIDGET_NAME) {
    return true;
  }

  return result;
}

std::shared_ptr<QWidget> DevicePluginViewProvider::getManagementWidget(const QString &key, QVariant arg) {
  std::shared_ptr<QWidget> result = nullptr;

  if (key == EDIT_CHANNEL_WIDGET_NAME) {
    bool is_ok;
    int channel_num = arg.toInt(&is_ok);

    if (is_ok) {
      if (_edit_channel_controller != nullptr) {
        _edit_channel_controller->setCurrentChannel(channel_num);
        result = _edit_channel_controller->getView();
      } else {
        qCritical() << "Edit channel controller is nullptr " << __func__;
      }
    } else {
      qCritical() << "Incorrect arg to Edit Channel Widget getter " << __func__;
    }
  }


  return result;
}
