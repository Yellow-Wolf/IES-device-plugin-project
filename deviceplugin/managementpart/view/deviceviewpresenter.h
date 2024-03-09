#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_DEVICEVIEWPRESENTER_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_DEVICEVIEWPRESENTER_H_

#include <memory>

#include <QObject>

#include "deviceplugin/managementpart/components/mainmanagement/views/deviceviewdata.h"


class DeviceViewPresenter: public QObject {
  Q_OBJECT
 public:
  explicit DeviceViewPresenter(QObject *parent = nullptr);

  virtual bool isInnerStartPeriodEnabled() = 0;
  virtual void setInnerStartPeriodEnabled(bool enabled) = 0;

  virtual uint64_t getInnerStartPeriod() = 0;
  virtual void setInnerStartPeriod(uint64_t value) = 0;

  virtual bool isInnerStartWidthEnabled() = 0;
  virtual void setInnerStartWidthEnabled(bool enabled) = 0;

  virtual uint64_t getInnerStartWidth() = 0;
  virtual void setInnerStartWidth(uint64_t value) = 0;

  virtual bool isInnerStartEnabledStatusEnabled() = 0;
  virtual void setInnerStartEnabledStatusEnabled(bool enabled) = 0;

  virtual uint64_t getInnerStartEnabledStatus() = 0;
  virtual void setInnerStartEnabledStatus(bool value) = 0;

  virtual bool isInnerStartInvertedStatusEnabled() = 0;
  virtual void setInnerStartInvertedStatusEnabled(bool enabled) = 0;

  virtual uint64_t getInnerStartInvertedStatus() = 0;
  virtual void setInnerStartInvertedStatus(bool value) = 0;


  virtual bool isChannelEnabledEnabled(int channel_num) = 0;
  virtual void setChannelEnabledEnabled(int channel_num, bool enabled) = 0;

  virtual bool isChannelEnabledVisible(int channel_num) = 0;
  virtual void setChannelEnabledVisible(int channel_num, bool visible) = 0;

  virtual bool getChannelEnabledValue(int channel_num) = 0;
  virtual void setChannelEnabledValue(int channel_num, bool value) = 0;



  virtual bool isChannelDelayEnabled(int channel_num) = 0;
  virtual void setChannelDelayEnabled(int channel_num, bool enabled) = 0;

  virtual uint64_t getChannelDelayValue(int channel_num) = 0;
  virtual void setChannelDelayValue(int channel_num, uint64_t value) = 0;

  virtual bool isChannelWidthEnabled(int channel_num) = 0;
  virtual void setChannelWidthEnabled(int channel_num, bool enabled) = 0;

  virtual uint64_t getChannelWidthValue(int channel_num) = 0;
  virtual void setChannelWidthValue(int channel_num, uint64_t value) = 0;

  virtual bool isChannelEnabledStatusEnabled(int channel_num) = 0;
  virtual void setChannelEnabledStatusEnabled(int channel_num, bool enabled) = 0;

  virtual bool getChannelEnabledStatusValue(int channel_num) = 0;
  virtual void setChannelEnabledStatusValue(int channel_num, bool value) = 0;

  virtual bool isChannelInvertedStatusEnabled(int channel_num) = 0;
  virtual void setChannelInvertedStatusEnabled(int channel_num, bool enabled) = 0;

  virtual bool getChannelInvertedStatusValue(int channel_num) = 0;
  virtual void setChannelInvertedStatusValue(int channel_num, bool value) = 0;

  virtual bool isChannelStartSourceEnabled(int channel_num) = 0;
  virtual void setChannelStartSourceEnabled(int channel_num, bool enabled) = 0;

  virtual uint16_t getChannelStartSourceValue(int channel_num) = 0;
  virtual void setChannelStartSourceValue(int channel_num, uint16_t value) = 0;

  virtual bool isChannelStartModeEnabled(int channel_num) = 0;
  virtual void setChannelStartModeEnabled(int channel_num, bool enabled) = 0;

  virtual ChannelMode getChannelStartModeValue(int channel_num) = 0;
  virtual void setChannelStartModeValue(int channel_num, ChannelMode value) = 0;


  virtual std::shared_ptr<ChannelViewData> getChannelData(int channel_num) = 0;

 signals:
  void innerStartPeriodValueChanged(uint64_t value);
  void innerStartPeriodEnabledChanged(bool enabled);

  void channelDelayValueChanged(int channel_num, uint64_t value);
  void channelDelayEnabledChanged(int channel_num, bool enabled);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_DEVICEVIEWPRESENTER_H_
