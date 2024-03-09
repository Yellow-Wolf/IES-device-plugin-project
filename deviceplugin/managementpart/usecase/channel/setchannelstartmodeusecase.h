#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELSTARTMODEUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELSTARTMODEUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct SetChannelStartModeUseCaseRequest {

};

struct SetChannelStartModeUseCaseResponse {
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class SetChannelStartModeUseCase : public QObject {
 Q_OBJECT
 public:
  explicit SetChannelStartModeUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                      const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                      QObject *parent = nullptr);

  SetChannelStartModeUseCaseResponse execute(SetChannelStartModeUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class SetChannelStartModeCommand : public Command {
 public:
  explicit SetChannelStartModeCommand(const std::shared_ptr<SetChannelStartModeUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<SetChannelStartModeUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELSTARTMODEUSECASE_H_
