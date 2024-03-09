#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELDELAYUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELDELAYUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct SetChannelDelayUseCaseRequest {

};

struct SetChannelDelayUseCaseResponse {
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class SetChannelDelayUseCase : public QObject {
 Q_OBJECT
 public:
  explicit SetChannelDelayUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                  const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                  QObject *parent = nullptr);

  SetChannelDelayUseCaseResponse execute(SetChannelDelayUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class SetChannelDelayCommand : public Command {
 public:
  explicit SetChannelDelayCommand(const std::shared_ptr<SetChannelDelayUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<SetChannelDelayUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELDELAYUSECASE_H_
