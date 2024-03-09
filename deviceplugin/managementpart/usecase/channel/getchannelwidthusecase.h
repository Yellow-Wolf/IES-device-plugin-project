#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELWIDTHUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELWIDTHUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelWidthUseCaseRequest {
  int channel_num;
};

struct GetChannelWidthUseCaseResponse {
  uint64_t value = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelWidthUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelWidthUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                  const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                  QObject *parent = nullptr);

  GetChannelWidthUseCaseResponse execute(GetChannelWidthUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class GetChannelWidthCommand : public Command {
 public:
  explicit GetChannelWidthCommand(const std::shared_ptr<GetChannelWidthUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelWidthUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELWIDTHUSECASE_H_
