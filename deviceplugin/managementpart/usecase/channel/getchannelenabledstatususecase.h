#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELENABLEDSTATUSUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELENABLEDSTATUSUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelEnabledStatusUseCaseRequest {
  int channel_num;
};

struct GetChannelEnabledStatusUseCaseResponse {
  bool value = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelEnabledStatusUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelEnabledStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                          const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                          QObject *parent = nullptr);

  GetChannelEnabledStatusUseCaseResponse execute(GetChannelEnabledStatusUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};


class GetChannelEnabledStatusCommand: public Command {
 public:
  explicit GetChannelEnabledStatusCommand(const std::shared_ptr<GetChannelEnabledStatusUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelEnabledStatusUseCase> _use_case = nullptr;
};
#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELENABLEDSTATUSUSECASE_H_
