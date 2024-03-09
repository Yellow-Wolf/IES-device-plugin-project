#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_CHANNELEDITDIALOG_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_CHANNELEDITDIALOG_H_

#include <QDialog>

#include <memory>

#include "deviceplugin/managementpart/components/mainmanagement/views/deviceviewdata.h"

class ChannelEditDialog: public QDialog {
  Q_OBJECT
 public:
  explicit ChannelEditDialog(QWidget *parent = nullptr);

  virtual void setChannelData(const std::shared_ptr<ChannelViewData> &data) = 0;

  virtual void setChannelNum(int num) = 0;
  virtual void setChannelName(int channel_num, const QString &value) = 0;
  virtual void setChannelDelay(int channel_num, uint64_t value) = 0;
  virtual void setChannelWidth(int channel_num, uint64_t value) = 0;
  virtual void setChannelEnabled(int channel_num, bool enabled) = 0;
  virtual void setChannelInverted(int channel_num, bool inverted) = 0;
  virtual void setChannelStartSource(int channel_num, uint16_t value) = 0;
  virtual void setChannelStartMode(int channel_num, ChannelMode value) = 0;

 signals:
  void channelNameChanged(int channel_num, const QString &value);

  void channelDelayChanged(int channel_num, uint64_t value);
  void channelWidthChanged(int channel_num, uint64_t value);
  void channelEnabledChanged(int channel_num, bool value);
  void channelInvertedChanged(int channel_num, bool value);

  void channelStartSourceChanged(int channel_num, uint16_t value);
  void channelStartModeChanged(int channel_num, uint16_t value);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_CHANNELEDITDIALOG_H_
