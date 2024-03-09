#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELENABLEDSTATUSUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELENABLEDSTATUSUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct SetChannelEnabledStatusUseCaseRequest {
  int channel_num;
  bool value;
};

struct SetChannelEnabledStatusUseCaseResponse {
  bool value;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class SetChannelEnabledStatusUseCase : public QObject {
 Q_OBJECT
 public:
  explicit SetChannelEnabledStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                          const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                          QObject *parent = nullptr);

  SetChannelEnabledStatusUseCaseResponse execute(SetChannelEnabledStatusUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class SetChannelEnabledStatusCommand : public Command {
 public:
  explicit SetChannelEnabledStatusCommand(const std::shared_ptr<SetChannelEnabledStatusUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<SetChannelEnabledStatusUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELENABLEDSTATUSUSECASE_H_
