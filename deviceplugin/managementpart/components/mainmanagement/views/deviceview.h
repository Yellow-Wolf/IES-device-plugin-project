#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_VIEW_TESTDEVICEVIEW_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_VIEW_TESTDEVICEVIEW_H_

#include <QWidget>


class DeviceView: public QWidget {
  Q_OBJECT
 public:
  explicit DeviceView(QWidget *parent = nullptr);

  virtual void setSyncSFPTemp(double value) = 0;
  virtual void setSyncSFPTxVoltage(double value) = 0;
  virtual void setSyncSFPTxAmperage(double value) = 0;
  virtual void setSyncSFPTxOpticalPower(double value) = 0;
  virtual void setSyncSFPRxPower(double value) = 0;

  virtual void setSyncDesLock(bool value) = 0;
  virtual void setSyncOscLock(bool value) = 0;
  virtual void setSyncRxLoss(bool value) = 0;
  virtual void setSyncTxFault(bool value) = 0;

  virtual void setInnerStartPeriod(uint64_t value) = 0;
  virtual void setInnerStartWidth(uint64_t value) = 0;
  virtual void setInnerStartEnabledStatus(bool value) = 0;
  virtual void setInnerStartInvertedStatus(bool value) = 0;

  virtual void setChannelName(int channel_num, const QString &channel_name) = 0;
  virtual void setChannelDelay(int channel_num, uint64_t value) = 0;
  virtual void setChannelWidth(int channel_num, uint64_t value) = 0;
  virtual void setChannelEnabledStatus(int channel_num, bool value) = 0;
  virtual void setChannelInvertedStatus(int channel_num, bool value) = 0;
  virtual void setChannelStartSource(int channel_num, uint16_t value) = 0;
  virtual void setChannelStartMode(int channel_num, uint16_t value) = 0;

 signals:
  void innerStartPeriodChanged(uint64_t value);
  void innerStartWidthChanged(uint64_t value);
  void innerStartEnabledStatusChanged(bool value);
  void innerStartInvertedStatusChanged(bool value);

  void channelNameChanged(int channel_num, const QString &name);
  void channelDelayChanged(int channel_num, uint64_t value);
  void channelWidthChanged(int channel_num, uint64_t value);
  void channelEnabledChanged(int channel_num, bool value);
  void channelInvertedChanged(int channel_num, bool value);
  void channelStartSourceChanged(int channel_num, int start_source);
  void channelStartModeChanged(int channel_num, int start_mode);

};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_VIEW_TESTDEVICEVIEW_H_
