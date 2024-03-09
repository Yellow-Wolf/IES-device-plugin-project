#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELSTARTMODEUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELSTARTMODEUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelStartModeUseCaseRequest {

};

struct GetChannelStartModeUseCaseResponse {
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelStartModeUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelStartModeUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                      const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                      QObject *parent = nullptr);

  GetChannelStartModeUseCaseResponse execute(GetChannelStartModeUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class GetChannelStartModeCommand : public Command {
 public:
  explicit GetChannelStartModeCommand(const std::shared_ptr<GetChannelStartModeUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelStartModeUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELSTARTMODEUSECASE_H_
