#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELSTARTSOURCEUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELSTARTSOURCEUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelStartSourceUseCaseRequest {

};

struct GetChannelStartSourceUseCaseResponse {
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelStartSourceUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelStartSourceUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                        const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                        QObject *parent = nullptr);

  GetChannelStartSourceUseCaseResponse execute(GetChannelStartSourceUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class GetChannelStartSourceCommand : public Command {
 public:
  explicit GetChannelStartSourceCommand(const std::shared_ptr<GetChannelStartSourceUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelStartSourceUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELSTARTSOURCEUSECASE_H_
