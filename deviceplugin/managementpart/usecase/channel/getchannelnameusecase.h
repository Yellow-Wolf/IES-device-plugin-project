#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELNAMEUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELNAMEUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelNameUseCaseRequest {
  int channel_num;
};

struct GetChannelNameUseCaseResponse {
  QString channel_name;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelNameUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelNameUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                 const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                 QObject *parent = nullptr);

  GetChannelNameUseCaseResponse execute(GetChannelNameUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class GetChannelNameCommand : public Command {
 public:
  explicit GetChannelNameCommand(const std::shared_ptr<GetChannelNameUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelNameUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELNAMEUSECASE_H_
