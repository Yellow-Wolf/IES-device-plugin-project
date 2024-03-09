#include "channeleditfactoryimpl1.h"
#include "deviceplugin/managementpart/components/channeldialog/views/impls/channeleditdialogimpl1.h"

ChannelEditFactoryImpl1::ChannelEditFactoryImpl1(const std::shared_ptr<DeviceCallbackSubscriptionFactory> &device_cb_factory,
                                                 const std::shared_ptr<UseCaseFactory> &use_case_factory):
                                                 _device_cb_factory(device_cb_factory),
                                                 _use_case_factory(use_case_factory) {

}

std::shared_ptr<ChannelEditController> ChannelEditFactoryImpl1::createChannelEditDialog() {
  std::shared_ptr<ChannelEditController> result = nullptr;

  if (_device_cb_factory != nullptr && _use_case_factory != nullptr) {
    std::shared_ptr<ChannelEditDialog> edit_view = nullptr;
    std::shared_ptr<ChannelEditController> channel_edit_controller = nullptr;

    if (_use_case_factory != nullptr) {
      auto get_channel_delay_use_case = _use_case_factory->createGetChannelDelayUseCase();
      auto set_channel_enabled_status_use_case = _use_case_factory->createSetChannelEnabledStatusUseCase();

      edit_view = std::make_shared<ChannelEditDialogImpl1>();
      channel_edit_controller = std::make_shared<ChannelEditController>(_device_cb_factory,
                                                                        edit_view,
                                                                        get_channel_delay_use_case,
                                                                        set_channel_enabled_status_use_case);

      result = channel_edit_controller;
    }
  }

  return result;
}
