#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELSTARTSOURCEUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELSTARTSOURCEUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct SetChannelStartSourceUseCaseRequest {

};

struct SetChannelStartSourceUseCaseResponse {
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class SetChannelStartSourceUseCase : public QObject {
 Q_OBJECT
 public:
  explicit SetChannelStartSourceUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                        const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                        QObject *parent = nullptr);

  SetChannelStartSourceUseCaseResponse execute(SetChannelStartSourceUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class SetChannelStartSourceCommand : public Command {
 public:
  explicit SetChannelStartSourceCommand(const std::shared_ptr<SetChannelStartSourceUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<SetChannelStartSourceUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELSTARTSOURCEUSECASE_H_
