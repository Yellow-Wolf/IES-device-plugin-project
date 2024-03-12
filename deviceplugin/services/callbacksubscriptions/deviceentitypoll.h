#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DOMAIN_CPSDEVICE_IMPLS_STANDALONEIMPL_CPSDEVICEENTITYPOLL_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DOMAIN_CPSDEVICE_IMPLS_STANDALONEIMPL_CPSDEVICEENTITYPOLL_H_

#include <QObject>

#include "threadpooling/iprocessable.h"

#include "devicecallbacksubscriptionfactory.h"
#include "deviceplugin/entity/deviceentity.h"

#include "ideviceentitypoll.h"


class DeviceEntityPoll: public IDeviceEntityPoll {
  Q_OBJECT
 public:
  explicit DeviceEntityPoll(const std::shared_ptr<DeviceEntity> &device_entity,
                            const std::shared_ptr<DeviceCallbackSubscriptionFactory> &callback_sub_factory,
                            QObject *parent = nullptr);

  void process() override;

  void SyncModuleStatusesPoll() override;
  void SyncSFPStatusesPoll() override;

  void channelNamesPoll() override;
  void channelDelaysPoll() override;
  void channelWidthsPoll() override;
  void channelStartSourcesPoll() override;
  void channelStartModesPoll() override;
  void channelEnabledStatusesPoll() override;
  void channelInvertedStatusesPoll() override;
  void innerStartPeriodPoll() override;
 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<DeviceCallbackSubscriptionFactory> _callback_sub_factory = nullptr;


};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DOMAIN_CPSDEVICE_IMPLS_STANDALONEIMPL_CPSDEVICEENTITYPOLL_H_
