#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_VIEWPROVIDERFACTORY_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_VIEWPROVIDERFACTORY_H_

#include <memory>
#include <plugin/deviceplugins/viewprovider.h>
#include "deviceplugin/managementpart/components/channeldialog/controllers/channeleditcontroller.h"

class ViewProviderFactory {
 public:
  std::shared_ptr<PluginViewProvider> createViewProvider(const std::shared_ptr<QWidget> &management_view,
                                                         const std::shared_ptr<ChannelEditController> &edit_channel_controller);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_VIEWPROVIDERFACTORY_H_
