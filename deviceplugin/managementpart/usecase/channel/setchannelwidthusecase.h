#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELWIDTHUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELWIDTHUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct SetChannelWidthUseCaseRequest {

};

struct SetChannelWidthUseCaseResponse {
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class SetChannelWidthUseCase : public QObject {
 Q_OBJECT
 public:
  explicit SetChannelWidthUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                  const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                  QObject *parent = nullptr);

  SetChannelWidthUseCaseResponse execute(SetChannelWidthUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class SetChannelWidthCommand : public Command {
 public:
  explicit SetChannelWidthCommand(const std::shared_ptr<SetChannelWidthUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<SetChannelWidthUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELWIDTHUSECASE_H_
