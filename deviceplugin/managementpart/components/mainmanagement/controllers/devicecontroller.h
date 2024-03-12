#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_CONTROLLER_TESTDEVICECONTROLLER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_CONTROLLER_TESTDEVICECONTROLLER_H_

#include "deviceplugin/managementpart/components/mainmanagement/views/deviceview.h"
#include "deviceplugin/managementpart/usecase/usecasefactory.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelenabledstatususecase.h"
#include "deviceplugin/services/callbacksubscriptions/impls/standaloneimpl/devicecallbacksubscriptionstandalonefactory.h"


class DeviceController: public QObject {
  Q_OBJECT
 public:
  explicit DeviceController(const std::shared_ptr<DeviceView> &test_device_view,
                            const std::shared_ptr<UseCaseFactory> &use_case_factory,
                            const std::shared_ptr<DeviceCallbackSubscriptionStandaloneFactory> &device_cb_factory,
                            QObject *parent = nullptr);


  // TODO: Переписать таким образом, чтобы передавать фабрику колбэков в конструкторе, а setConnections сделать приватным
  void setConnections();


 private:
  std::shared_ptr<DeviceView> _device_view = nullptr;
  std::shared_ptr<UseCaseFactory> _use_case_factory = nullptr;

  std::shared_ptr<DeviceCallbackSubscriptionFactory> _device_cb_factory = nullptr;

 private slots:
    void innerStartPeriodModelChangedSlot(quint64 value);
  void channelNameChangedViewSlot(int channel_num, const QString &value);
  void channelEnabledStatusChangedViewSlot(int channel_num, bool value);

  void syncDesLockModelChangedSlot(bool value);
  void syncOscLockModelChangedSlot(bool value);
  void syncRxLossModelChangedSlot(bool value);
  void syncTxFaultModelChangedSlot(bool value);

  void syncSFPTempModelChangedSlot(double value);
  void syncSFPTxVoltageModelChangedSlot(double value);
  void syncSFPTxAmperageModelChangedSlot(double value);
  void syncSFPTxOpticalPowerModelChangedSlot(double value);
  void syncSFPRxPowerModelChangedSlot(double value);

  void channelNameModelChangedSlot(const QVector<QString> &value);
  void channelDelaysModelChangedSlot(const QVector<uint64_t> &value);
  void channelWidthsModelChangedSlot(const QVector<uint64_t> &value);
  void channelEnabledStatusesModelChangedSlot(const QVector<bool> &value);
  void channelInvertedStatusesModelChangedSlot(const QVector<bool> &value);
  void channelStartSourcesModelChangedSlot(const QVector<uint16_t> &value);
  void channelStartModesModelChangedSlot(const QVector<uint16_t> &value);

};


#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_MANAGEMENTPART_CONTROLLER_TESTDEVICECONTROLLER_H_
