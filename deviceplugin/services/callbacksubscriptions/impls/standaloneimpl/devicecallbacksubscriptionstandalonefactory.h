#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_DEVICES_CPSDEVICE_CPSDEVICECALLBACKSUBSCRIPTIONFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_DEVICES_CPSDEVICE_CPSDEVICECALLBACKSUBSCRIPTIONFACTORY_H_

#include <QObject>

#include <memory>

#include "deviceplugin/services/callbacksubscriptions/devicecallbacksubscriptionfactory.h"

class DeviceCallbackSubscriptionStandaloneFactory: public DeviceCallbackSubscriptionFactory {
  Q_OBJECT
 public:
  explicit DeviceCallbackSubscriptionStandaloneFactory(QObject *parent = nullptr);

  std::shared_ptr<ULong64ValueCallback> getInnerStartPeriodCallback() override;
  std::shared_ptr<DoubleValueCallback> getSyncSFPTempCallback() override;
  std::shared_ptr<DoubleValueCallback> getSyncSFPTxVoltageCallback() override;
  std::shared_ptr<DoubleValueCallback> getSyncSFPTxAmperageCallback() override;
  std::shared_ptr<DoubleValueCallback> getSyncSFPTxOpticalPowerCallback() override;
  std::shared_ptr<DoubleValueCallback> getSyncSFPRxPowerCallback() override;
  std::shared_ptr<BoolValueCallback> getSyncDesLockCallback() override;
  std::shared_ptr<BoolValueCallback> getSyncOscLockCallback() override;
  std::shared_ptr<BoolValueCallback> getSyncRxLossCallback() override;
  std::shared_ptr<BoolValueCallback> getSyncTxFaultCallback() override;
  std::shared_ptr<ULong64ValueCallback> getInnerStartWidthCallback() override;
  std::shared_ptr<BoolValueCallback> getInnerStartEnabledStatusCallback() override;
  std::shared_ptr<BoolValueCallback> getInnerStartInvertedStatusCallback() override;
  std::shared_ptr<ULong64ValuesCallback> getChannelWidthsCallback() override;
  std::shared_ptr<BoolValuesCallback> getChannelEnabledStatusesCallback() override;
  std::shared_ptr<BoolValuesCallback> getChannelInvertedStatusesCallback() override;
  std::shared_ptr<UShortValuesCallback> getChannelStartSourcesCallback() override;
  std::shared_ptr<UShortValuesCallback> getChannelStartModesCallback() override;

  std::shared_ptr<StringValuesCallback> getChannelNameCallback() override;
  std::shared_ptr<ULong64ValuesCallback> getChannelDelaysCallback() override;


 private:
  std::shared_ptr<BoolValueCallback> _sync_des_lock_callback = nullptr;
  std::shared_ptr<BoolValueCallback> _sync_osc_lock_callback = nullptr;
  std::shared_ptr<BoolValueCallback> _sync_rx_loss_callback = nullptr;
  std::shared_ptr<BoolValueCallback> _sync_tx_fault_callback = nullptr;

  std::shared_ptr<DoubleValueCallback> _sync_sfp_temp_callback = nullptr;
  std::shared_ptr<DoubleValueCallback> _sync_sfp_tx_voltage_callback = nullptr;
  std::shared_ptr<DoubleValueCallback> _sync_sfp_tx_amperage_callback = nullptr;
  std::shared_ptr<DoubleValueCallback> _sync_sfp_tx_optical_power_callback = nullptr;
  std::shared_ptr<DoubleValueCallback> _sync_sfp_rx_power_callback = nullptr;

  std::shared_ptr<ULong64ValueCallback> _inner_start_period_callback = nullptr;
  std::shared_ptr<ULong64ValueCallback> _inner_start_width_callback = nullptr;
  std::shared_ptr<BoolValueCallback> _inner_start_enabled_status_callback = nullptr;
  std::shared_ptr<BoolValueCallback> _inner_start_inverted_status_callback = nullptr;

  std::shared_ptr<StringValuesCallback> _channel_name_callback = nullptr;
  std::shared_ptr<ULong64ValuesCallback> _channel_delays_callback = nullptr;
  std::shared_ptr<ULong64ValuesCallback> _channel_widths_callback = nullptr;
  std::shared_ptr<BoolValuesCallback> _channel_enabled_statuses_callback = nullptr;
  std::shared_ptr<BoolValuesCallback> _channel_inverted_statuses_callback = nullptr;
  std::shared_ptr<UShortValuesCallback> _channel_start_sources_callback = nullptr;
  std::shared_ptr<UShortValuesCallback> _channel_start_modes_callback = nullptr;

};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_DEVICES_CPSDEVICE_CPSDEVICECALLBACKSUBSCRIPTIONFACTORY_H_
