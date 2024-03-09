#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_DEVICEVIEWDATA_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_DEVICEVIEWDATA_H_

#include <QVector>

#include "deviceplugin/consts.h"
#include "deviceplugin/entity/devicetypes.h"


struct SFPViewData {
  QString temp;
  QString tx_voltage;
  QString tx_amperage;
  QString tx_optical_power;
  QString rx_power;
};

struct ChannelViewData {
  QString channel_name;

  uint64_t channel_delay_value = 0;
  bool is_channel_delay_enabled = true;

  uint64_t channel_width_value = 0;
  bool is_channel_width_enabled = true;

  bool enabled_enabled = true;
  bool enabled_status = false;
  bool enabled_visible = true;

  bool inverted_enabled = true;
  bool inverted_status = false;
  bool inverted_visible = true;

  uint16_t start_source_value = 0;
  bool start_source_enabled = true;

  ChannelMode start_mode_value = PROXY;
  bool start_mode_enabled = true;
};

struct DeviceViewData {
  SFPViewData sync_sfp_data;

  bool sync_des_lock = false;
  bool sync_osc_lock = false;
  bool sync_rx_loss = false;
  bool sync_tx_fault = false;

  bool get_sync_sfp_enabled = true;
  double sync_sfp_temp = 0.;
  double sync_sft_tx_voltage = 0.;
  double sync_sfp_tx_amperage = 0.;
  double sync_sfp_tx_optical_power = 0.;
  double sync_sfp_rx_power = 0.;

  uint64_t inner_start_period_value = 0;
  bool inner_start_period_enabled = true;

  uint64_t inner_start_width_value = 0;
  bool inner_start_width_enabled = true;

  bool enabled_enabled = true;
  bool enabled_status = false;
  bool enabled_visible = true;

  bool inverted_enabled = true;
  bool inverted_status = false;
  bool inverted_visible = true;

  QVector<ChannelViewData> channels_data = QVector<ChannelViewData>(CHANNEL_COUNT);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_VIEW_DEVICEVIEWDATA_H_
