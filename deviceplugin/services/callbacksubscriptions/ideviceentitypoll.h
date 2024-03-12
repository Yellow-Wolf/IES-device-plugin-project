#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_CALLBACKSUBSCRIPTIONS_IDEVICEENTITYPOLL_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_CALLBACKSUBSCRIPTIONS_IDEVICEENTITYPOLL_H_

#include <QObject>

#include <threadpooling/iprocessable.h>


class IDeviceEntityPoll: public QObject, public IProcessable {
  Q_OBJECT
 public:
  explicit IDeviceEntityPoll(QObject *parent = nullptr);

  virtual void SyncModuleStatusesPoll() = 0;
  virtual void SyncSFPStatusesPoll() = 0;
  virtual void innerStartPeriodPoll() = 0;
  virtual void channelNamesPoll() = 0;
  virtual void channelDelaysPoll() = 0;
  virtual void channelWidthsPoll() = 0;
  virtual void channelStartSourcesPoll() = 0;
  virtual void channelStartModesPoll() = 0;
  virtual void channelEnabledStatusesPoll() = 0;
  virtual void channelInvertedStatusesPoll() = 0;
};
#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_CALLBACKSUBSCRIPTIONS_IDEVICEENTITYPOLL_H_
