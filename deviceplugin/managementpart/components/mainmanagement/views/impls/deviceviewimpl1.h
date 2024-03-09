#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_TESTDEVICEVIEWIMPL1_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_TESTDEVICEVIEWIMPL1_H_

#include <memory>

#include <QDialog>

#include <widgets/common/basic/statebutton.h>
#include <widgets/common/basic/standardbutton.h>
#include <widgets/common/composed/sfpstatusesdialog.h>

#include "deviceplugin/managementpart/components/mainmanagement/views/deviceview.h"
#include "deviceplugin/widgets/epss/composed/syncmodulewidget.h"
#include "deviceplugin/widgets/epss/composed/innerstartsettingswidget.h"
#include "deviceplugin/widgets/epss/composed/fullchannelsettings.h"
#include "deviceplugin/widgets/t831/channelsbox/channelsboxv2.h"
#include "deviceplugin/widgets/t831/channelsbox/channelscountstrategy.h"

#include "deviceplugin/managementpart/components/mainmanagement/views/deviceviewdata.h"


class DeviceViewImpl1: public DeviceView {
  Q_OBJECT
 public:
  explicit DeviceViewImpl1(const QString &caption, QWidget *parent = nullptr);

  void setInnerStartPeriod(uint64_t value) override;

  void setChannelDelay(int channel_num, uint64_t value) override;

  void setSyncSFPTemp(double value) override;
  void setSyncSFPTxVoltage(double value) override;
  void setSyncSFPTxAmperage(double value) override;
  void setSyncSFPTxOpticalPower(double value) override;
  void setSyncSFPRxPower(double value) override;
  void setSyncDesLock(bool value) override;
  void setSyncOscLock(bool value) override;
  void setSyncRxLoss(bool value) override;
  void setSyncTxFault(bool value) override;
  void setInnerStartWidth(uint64_t value) override;
  void setInnerStartEnabledStatus(bool value) override;
  void setInnerStartInvertedStatus(bool value) override;

  void setChannelName(int channel_num, const QString &channel_name) override;
  void setChannelWidth(int channel_num, uint64_t value) override;
  void setChannelEnabledStatus(int channel_num, bool value) override;
  void setChannelInvertedStatus(int channel_num, bool value) override;
  void setChannelStartSource(int channel_num, uint16_t value) override;
  void setChannelStartMode(int channel_num, uint16_t value) override;

 private:
  int _channel_num = -1;

  std::shared_ptr<DeviceViewData> _device_view_data = nullptr;

  SyncModuleWidget *_sync_module_widget = nullptr;
  SFPStatusesDialog *_sync_sfp_statuses_widget = nullptr;

  InnerStartSettingsWidget *_inner_start_settings_widget = nullptr;

  FullChannelSettings *_channel_settings = nullptr;
  ChannelsBoxV2 *_channels_box = nullptr;
  ChannelsCountStrategy *_channels_count_strategy = nullptr;

  StandardButton *_add_delay_for_group_of_channels_button = nullptr;


  void initUI(const QString &caption);
  void setConnections();


 private slots:
  void innerStartPeriodChangedSlot(uint64_t value);
  void innerStartWidthChangedSlot(uint64_t value);
  void innerStartEnabledStatusChangedSlot(bool value);
  void innerStartInvertedStatusChangedSlot(bool value);

  void syncSFPOpenParamsSlot();

  void currentChannelChangedBridgeSlot(int channel_num);

  void channelNameChangedBridgeSlot(const QString &name);
  void channelEnabledStatusChangedBridgeSlot(bool value);
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_VIEW_IMPLS_TESTDEVICEVIEWIMPL1_H_
