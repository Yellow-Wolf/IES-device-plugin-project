#include "devicecallbacksubscriptionstandalonefactory.h"

#include <callbacks/models/impls/standaloneimpl/standalonevaluecallbacks.h>


DeviceCallbackSubscriptionStandaloneFactory::DeviceCallbackSubscriptionStandaloneFactory(QObject *parent)
    : DeviceCallbackSubscriptionFactory(parent) {

}

std::shared_ptr<ULong64ValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getInnerStartPeriodCallback() {
  if (_inner_start_period_callback == nullptr) {
    _inner_start_period_callback = std::make_shared<ULong64ValueCallback>();
  }

  return _inner_start_period_callback;
}

std::shared_ptr<ULong64ValuesCallback> DeviceCallbackSubscriptionStandaloneFactory::getChannelDelaysCallback() {
  if (_channel_delays_callback == nullptr) {
    _channel_delays_callback = std::make_shared<ULong64ValuesCallback>();
  }
  return _channel_delays_callback;
}

std::shared_ptr<DoubleValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncSFPTempCallback() {
  if (_sync_sfp_temp_callback == nullptr) {
    _sync_sfp_temp_callback = std::make_shared<DoubleValueCallback>();
  }
  return _sync_sfp_temp_callback;
}

std::shared_ptr<DoubleValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncSFPTxVoltageCallback() {
  if (_sync_sfp_tx_voltage_callback == nullptr) {
    _sync_sfp_tx_voltage_callback = std::make_shared<DoubleValueCallback>();
  }
  return _sync_sfp_tx_voltage_callback;
}

std::shared_ptr<DoubleValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncSFPTxAmperageCallback() {
  if (_sync_sfp_tx_amperage_callback == nullptr) {
    _sync_sfp_tx_amperage_callback = std::make_shared<DoubleValueCallback>();
  }
  return _sync_sfp_tx_amperage_callback;
}

std::shared_ptr<DoubleValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncSFPTxOpticalPowerCallback() {
  if (_sync_sfp_tx_optical_power_callback == nullptr) {
    _sync_sfp_tx_optical_power_callback = std::make_shared<DoubleValueCallback>();
  }
  return _sync_sfp_tx_optical_power_callback;
}

std::shared_ptr<DoubleValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncSFPRxPowerCallback() {
  if (_sync_sfp_rx_power_callback == nullptr) {
    _sync_sfp_rx_power_callback = std::make_shared<DoubleValueCallback>();
  }
  return _sync_sfp_rx_power_callback;
}

std::shared_ptr<BoolValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncDesLockCallback() {
  if (_sync_des_lock_callback == nullptr) {
    _sync_des_lock_callback = std::make_shared<BoolValueCallback>();
  }
  return _sync_des_lock_callback;
}

std::shared_ptr<BoolValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncOscLockCallback() {
  if (_sync_osc_lock_callback == nullptr) {
    _sync_osc_lock_callback = std::make_shared<BoolValueCallback>();
  }
  return _sync_osc_lock_callback;
}

std::shared_ptr<BoolValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncRxLossCallback() {
  if (_sync_rx_loss_callback == nullptr) {
    _sync_rx_loss_callback = std::make_shared<BoolValueCallback>();
  }
  return _sync_rx_loss_callback;
}

std::shared_ptr<BoolValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getSyncTxFaultCallback() {
  if (_sync_tx_fault_callback == nullptr) {
    _sync_tx_fault_callback = std::make_shared<BoolValueCallback>();
  }
  return _sync_tx_fault_callback;
}

std::shared_ptr<ULong64ValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getInnerStartWidthCallback() {
  if (_inner_start_width_callback == nullptr) {
    _inner_start_width_callback = std::make_shared<ULong64ValueCallback>();
  }
  return _inner_start_width_callback;
}

std::shared_ptr<BoolValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getInnerStartEnabledStatusCallback() {
  if (_inner_start_enabled_status_callback == nullptr) {
    _inner_start_enabled_status_callback = std::make_shared<BoolValueCallback>();
  }
  return _inner_start_enabled_status_callback;
}

std::shared_ptr<BoolValueCallback> DeviceCallbackSubscriptionStandaloneFactory::getInnerStartInvertedStatusCallback() {
  if (_inner_start_inverted_status_callback == nullptr) {
    _inner_start_inverted_status_callback = std::make_shared<BoolValueCallback>();
  }
  return _inner_start_inverted_status_callback;
}

std::shared_ptr<ULong64ValuesCallback> DeviceCallbackSubscriptionStandaloneFactory::getChannelWidthsCallback() {
  if (_channel_widths_callback == nullptr) {
    _channel_widths_callback = std::make_shared<ULong64ValuesCallback>();
  }
  return _channel_widths_callback;
}

std::shared_ptr<BoolValuesCallback> DeviceCallbackSubscriptionStandaloneFactory::getChannelEnabledStatusesCallback() {
  if (_channel_enabled_statuses_callback == nullptr) {
    _channel_enabled_statuses_callback = std::make_shared<BoolValuesCallback>();
  }
  return _channel_enabled_statuses_callback;
}

std::shared_ptr<BoolValuesCallback> DeviceCallbackSubscriptionStandaloneFactory::getChannelInvertedStatusesCallback() {
  if (_channel_inverted_statuses_callback == nullptr) {
    _channel_inverted_statuses_callback = std::make_shared<BoolValuesCallback>();
  }
  return _channel_inverted_statuses_callback;
}

std::shared_ptr<UShortValuesCallback> DeviceCallbackSubscriptionStandaloneFactory::getChannelStartSourcesCallback() {
  if (_channel_start_sources_callback == nullptr) {
    _channel_start_sources_callback = std::make_shared<UShortValuesCallback>();
  }
  return _channel_start_sources_callback;
}

std::shared_ptr<UShortValuesCallback> DeviceCallbackSubscriptionStandaloneFactory::getChannelStartModesCallback() {
  if (_channel_start_modes_callback == nullptr) {
    _channel_start_modes_callback = std::make_shared<UShortValuesCallback>();
  }
  return _channel_start_modes_callback;
}

std::shared_ptr<StringValuesCallback> DeviceCallbackSubscriptionStandaloneFactory::getChannelNameCallback() {
  if (_channel_name_callback == nullptr) {
    _channel_name_callback = std::make_shared<StringValuesCallback>();
  }
  return _channel_name_callback;
}

