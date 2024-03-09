#include "viewproviderfactory.h"

#include <plugin/deviceplugins/viewproviders/viewproviderimpl1.h>

static const std::string EDIT_CHANNEL_VIEW_KEY = "EditChannel";


std::shared_ptr<PluginViewProvider> ViewProviderFactory::createViewProvider(const std::shared_ptr<QWidget> &management_view,
                                                                            const std::shared_ptr<ChannelEditController> &edit_channel_controller) {


  std::shared_ptr<PluginViewProvider> result = nullptr;

  if (management_view != nullptr && edit_channel_controller != nullptr) {
    result = std::make_shared<ViewProviderImpl1>();
    result->setMainManagementWidget(management_view);

    auto edit_channel_view = edit_channel_controller->getView();
    result->addExtraWidget(EDIT_CHANNEL_VIEW_KEY.c_str(), edit_channel_view);
  }

  return result;
}
