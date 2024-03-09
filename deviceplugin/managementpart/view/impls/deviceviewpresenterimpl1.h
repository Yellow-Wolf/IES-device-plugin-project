#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_DEVICEVIEWPRESENTERIMPL1_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_DEVICEVIEWPRESENTERIMPL1_H_

#include "deviceplugin/managementpart/view/deviceviewpresenter.h"


class DeviceViewPresenterImpl1: public DeviceViewPresenter {
 public:
  explicit DeviceViewPresenterImpl1(const std::shared_ptr<DeviceViewData> &data,
                                    QObject *parent = nullptr);

  bool isInnerStartPeriodEnabled() override;
  void setInnerStartPeriodEnabled(bool enabled) override;

  uint64_t getInnerStartPeriod() override;
  void setInnerStartPeriod(uint64_t value) override;

  bool isChannelEnabledEnabled(int channel_num) override;
  void setChannelEnabledEnabled(int channel_num, bool enabled) override;

  bool isChannelEnabledVisible(int channel_num) override;
  void setChannelEnabledVisible(int channel_num, bool visible) override;

  bool getChannelEnabledValue(int channel_num) override;
  void setChannelEnabledValue(int channel_num, bool value) override;

  bool isChannelDelayEnabled(int channel_num) override;
  void setChannelDelayEnabled(int channel_num, bool enabled) override;

  uint64_t getChannelDelayValue(int channel_num) override;
  void setChannelDelayValue(int channel_num, uint64_t value) override;

  bool isInnerStartWidthEnabled() override;
  void setInnerStartWidthEnabled(bool enabled) override;
  uint64_t getInnerStartWidth() override;
  void setInnerStartWidth(uint64_t value) override;
  bool isInnerStartEnabledStatusEnabled() override;
  void setInnerStartEnabledStatusEnabled(bool enabled) override;
  uint64_t getInnerStartEnabledStatus() override;
  void setInnerStartEnabledStatus(bool value) override;
  bool isInnerStartInvertedStatusEnabled() override;
  void setInnerStartInvertedStatusEnabled(bool enabled) override;
  uint64_t getInnerStartInvertedStatus() override;
  void setInnerStartInvertedStatus(bool value) override;
  bool isChannelWidthEnabled(int channel_num) override;
  void setChannelWidthEnabled(int channel_num, bool enabled) override;
  uint64_t getChannelWidthValue(int channel_num) override;
  void setChannelWidthValue(int channel_num, uint64_t value) override;
  bool isChannelEnabledStatusEnabled(int channel_num) override;
  void setChannelEnabledStatusEnabled(int channel_num, bool enabled) override;
  bool getChannelEnabledStatusValue(int channel_num) override;
  void setChannelEnabledStatusValue(int channel_num, bool value) override;
  bool isChannelInvertedStatusEnabled(int channel_num) override;
  void setChannelInvertedStatusEnabled(int channel_num, bool enabled) override;
  bool getChannelInvertedStatusValue(int channel_num) override;
  void setChannelInvertedStatusValue(int channel_num, bool value) override;
  bool isChannelStartSourceEnabled(int channel_num) override;
  void setChannelStartSourceEnabled(int channel_num, bool enabled) override;
  uint16_t getChannelStartSourceValue(int channel_num) override;
  void setChannelStartSourceValue(int channel_num, uint16_t value) override;
  bool isChannelStartModeEnabled(int channel_num) override;
  void setChannelStartModeEnabled(int channel_num, bool enabled) override;
  ChannelMode getChannelStartModeValue(int channel_num) override;
  void setChannelStartModeValue(int channel_num, ChannelMode value) override;

  std::shared_ptr<ChannelViewData> getChannelData(int channel_num) override;

 private:
  std::shared_ptr<DeviceViewData> _data = nullptr;

  bool isChannelValid(int channel_num);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_DEVICEVIEWPRESENTERIMPL1_H_
