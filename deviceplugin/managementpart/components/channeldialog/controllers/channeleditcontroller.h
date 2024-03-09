#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_CONTROLLER_CHANNELEDITCONTROLLER_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_CONTROLLER_CHANNELEDITCONTROLLER_H_

#include <memory>

#include <QObject>
#include "deviceplugin/managementpart/usecase/channel/getchanneldelayusecase.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelenabledstatususecase.h"
#include "deviceplugin/managementpart/components/channeldialog/views/channeleditdialog.h"

#include "deviceplugin/services/callbacksubscriptions/devicecallbacksubscriptionfactory.h"

class ChannelEditController: public QObject {
  Q_OBJECT
 public:
  explicit ChannelEditController(const std::shared_ptr<DeviceCallbackSubscriptionFactory> &device_cb_factory,
                                 const std::shared_ptr<ChannelEditDialog> &channel_edit_view,
                                 const std::shared_ptr<GetChannelDelayUseCase> &get_channel_delay_use_case,
                                 const std::shared_ptr<SetChannelEnabledStatusUseCase> &set_channel_enabled_status_use_case,
                                 QObject *parent = nullptr);

  void setCurrentChannel(int current_channel);

  std::shared_ptr<QWidget> getView();


 private:
  int _current_channel = 0;
  std::shared_ptr<ChannelEditDialog> _channel_edit_view = nullptr;
  std::shared_ptr<GetChannelDelayUseCase> _get_channel_delay_use_case = nullptr;
  std::shared_ptr<SetChannelEnabledStatusUseCase> _set_channel_enabled_status_use_case = nullptr;

  std::shared_ptr<DeviceCallbackSubscriptionFactory> _device_cb_factory = nullptr;

  void setConnections();

 private slots:
  void channelNameModelChangedSlot(const QVector<QString> &values);
  void channelDelaysChangedModelSlot(const QVector<uint64_t> &values);
  void channelWidthsChangedModelSlot(const QVector<uint64_t> &values);
  void channelEnabledStatusesChangedModelSlot(const QVector<bool> &values);
  void channelInvertedStatusesChangedModelSlot(const QVector<bool> &values);
  void channelStartSourceChangedModelSlot(const QVector<uint16_t> &values);
  void channelStartModesChangedModelSlot(const QVector<uint16_t> &values);

  void channelNameChangedViewSlot(int channel_num, const QString &value);
  void channelDelayChangedViewSlot(int channel_num, uint64_t value);
  void channelEnabledStatusChangedViewSlot(int channel_num, bool value);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_CONTROLLER_CHANNELEDITCONTROLLER_H_
