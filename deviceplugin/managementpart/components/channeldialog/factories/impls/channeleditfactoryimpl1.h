#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CHANNELDIALOG_FACTORIES_IMPLS_CHANNELEDITFACTORYIMPL1_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CHANNELDIALOG_FACTORIES_IMPLS_CHANNELEDITFACTORYIMPL1_H_

#include "deviceplugin/managementpart/components/channeldialog/factories/channeleditfactory.h"
#include "deviceplugin/services/callbacksubscriptions/devicecallbacksubscriptionfactory.h"
#include "deviceplugin/managementpart/usecase/usecasefactory.h"
#include "deviceplugin/managementpart/components/channeldialog/controllers/channeleditcontroller.h"


class ChannelEditFactoryImpl1: public ChannelEditFactory {
 public:
  explicit ChannelEditFactoryImpl1(const std::shared_ptr<DeviceCallbackSubscriptionFactory> &device_cb_factory,
                                   const std::shared_ptr<UseCaseFactory> &use_case_factory);

  std::shared_ptr<ChannelEditController> createChannelEditDialog() override;

 private:
  std::shared_ptr<DeviceCallbackSubscriptionFactory> _device_cb_factory = nullptr;
  std::shared_ptr<UseCaseFactory> _use_case_factory = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_COMPONENTS_CHANNELDIALOG_FACTORIES_IMPLS_CHANNELEDITFACTORYIMPL1_H_
