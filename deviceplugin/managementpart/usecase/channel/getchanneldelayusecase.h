#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_GETCHANNELDELAYUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_GETCHANNELDELAYUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelDelayUseCaseRequest {
  int channel_num;
};

struct GetChannelDelayUseCaseResponse {
  uint64_t value = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelDelayUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelDelayUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                  const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                  QObject *parent = nullptr);

  GetChannelDelayUseCaseResponse execute(GetChannelDelayUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class GetChannelDelayCommand : public Command {
 public:
  explicit GetChannelDelayCommand(const std::shared_ptr<GetChannelDelayUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelDelayUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_GETCHANNELDELAYUSECASE_H_
