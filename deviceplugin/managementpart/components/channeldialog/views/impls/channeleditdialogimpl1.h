#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_CHANNELEDITDIALOGIMPL1_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_CHANNELEDITDIALOGIMPL1_H_

#include <widgets/common/composed/fullcomposedtimeinput.h>

#include "deviceplugin/managementpart/components/channeldialog/views/channeleditdialog.h"
#include "deviceplugin/managementpart/components/mainmanagement/views/deviceviewdata.h"

#include "deviceplugin/widgets/t831/statebuttonwithlabel.h"

#include "deviceplugin/widgets/epss/composed/fullchannelsettings.h"


class ChannelEditDialogImpl1: public ChannelEditDialog {
 public:
  explicit ChannelEditDialogImpl1(QWidget *parent = nullptr);

  void setChannelData(const std::shared_ptr<ChannelViewData> &data) override;

  void setChannelNum(int num) override;
  void setChannelName(int channel_num, const QString &value) override;
  void setChannelDelay(int channel_num, uint64_t value) override;
  void setChannelWidth(int channel_num, uint64_t value) override;
  void setChannelEnabled(int channel_num, bool enabled) override;
  void setChannelInverted(int channel_num, bool inverted) override;
  void setChannelStartSource(int channel_num, uint16_t value) override;
  void setChannelStartMode(int channel_num, ChannelMode value) override;

 private:
  QString _dialog_name_prefix = "Настройки канала: ";

  int _channel_num = -1;

  std::shared_ptr<FullChannelSettings> _channel_settings = nullptr;

//  std::shared_ptr<FullChannelSettings>

  std::shared_ptr<DeviceViewData> _data = nullptr;

  void initUI();
  void setConnections();

  bool isChannelValid(int channel_num);

  void setChannelName(const QString &value);
  void setChannelDelay(uint64_t value);
  void setChannelWidth(uint64_t value);
  void setChannelEnabled(bool enabled);
  void setChannelInverted(bool inverted);
  void setChannelStartSource(uint16_t value);
  void setChannelStartMode(ChannelMode value);

 private slots:
  void acceptButtonClickedBridgeSlot();
  void cancelButtonClickedBridgeSlot();

  void delayChangedBridgeSlot(uint64_t value);
  void widthChangedBridgeSlot(uint64_t value);
  void enabledChangedBridgeSlot(bool value);
  void invertedChangedBridgeSlot(bool value);

  void startModeChangedBridgeSlot(uint16_t value);
  void startSourceChangedBridgeSlot(uint16_t value);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_CHANNELEDITDIALOGIMPL1_H_
