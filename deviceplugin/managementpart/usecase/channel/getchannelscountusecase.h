#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_GETCHANNELCOUNTUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_GETCHANNELCOUNTUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelsCountUseCaseRequest {

};

struct GetChannelsCountUseCaseResponse {
  int result = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelsCountUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelsCountUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                   const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                   QObject *parent = nullptr);

  GetChannelsCountUseCaseResponse execute(GetChannelsCountUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class GetChannelsCountCommand : public Command {
 public:
  explicit GetChannelsCountCommand(const std::shared_ptr<GetChannelsCountUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelsCountUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_GETCHANNELCOUNTUSECASE_H_
