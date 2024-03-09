#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_DEVICES_CPSDEVICE_CPSDEVICECALLBACKSUBSCRIPTIONFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_DEVICES_CPSDEVICE_CPSDEVICECALLBACKSUBSCRIPTIONFACTORY_H_

#include <QObject>

#include <memory>

#include <callbacks/models/valuecallbacks.h>


class DeviceCallbackSubscriptionFactory: public QObject {
  Q_OBJECT
 public:
  explicit DeviceCallbackSubscriptionFactory(QObject *parent = nullptr);

  virtual std::shared_ptr<DoubleValueCallback> getSyncSFPTempCallback() = 0;
  virtual std::shared_ptr<DoubleValueCallback> getSyncSFPTxVoltageCallback() = 0;
  virtual std::shared_ptr<DoubleValueCallback> getSyncSFPTxAmperageCallback() = 0;
  virtual std::shared_ptr<DoubleValueCallback> getSyncSFPTxOpticalPowerCallback() = 0;
  virtual std::shared_ptr<DoubleValueCallback> getSyncSFPRxPowerCallback() = 0;

  virtual std::shared_ptr<BoolValueCallback> getSyncDesLockCallback() = 0;
  virtual std::shared_ptr<BoolValueCallback> getSyncOscLockCallback() = 0;
  virtual std::shared_ptr<BoolValueCallback> getSyncRxLossCallback() = 0;
  virtual std::shared_ptr<BoolValueCallback> getSyncTxFaultCallback() = 0;

  virtual std::shared_ptr<ULong64ValueCallback> getInnerStartPeriodCallback() = 0;
  virtual std::shared_ptr<ULong64ValueCallback> getInnerStartWidthCallback() = 0;
  virtual std::shared_ptr<BoolValueCallback> getInnerStartEnabledStatusCallback() = 0;
  virtual std::shared_ptr<BoolValueCallback> getInnerStartInvertedStatusCallback() = 0;

  virtual std::shared_ptr<StringValuesCallback> getChannelNameCallback() = 0;
  virtual std::shared_ptr<ULong64ValuesCallback> getChannelDelaysCallback() = 0;
  virtual std::shared_ptr<ULong64ValuesCallback> getChannelWidthsCallback() = 0;
  virtual std::shared_ptr<BoolValuesCallback> getChannelEnabledStatusesCallback() = 0;
  virtual std::shared_ptr<BoolValuesCallback> getChannelInvertedStatusesCallback() = 0;
  virtual std::shared_ptr<UShortValuesCallback> getChannelStartSourcesCallback() = 0;
  virtual std::shared_ptr<UShortValuesCallback> getChannelStartModesCallback() = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_DEVICES_CPSDEVICE_CPSDEVICECALLBACKSUBSCRIPTIONFACTORY_H_
