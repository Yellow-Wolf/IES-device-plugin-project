#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELNAMEUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELNAMEUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct SetChannelNameUseCaseRequest {
  int channel_num;
  QString channel_name;
};

struct SetChannelNameUseCaseResponse {
  QString channel_name;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class SetChannelNameUseCase : public QObject {
 Q_OBJECT
 public:
  explicit SetChannelNameUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                 const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                 QObject *parent = nullptr);

  SetChannelNameUseCaseResponse execute(SetChannelNameUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class SetChannelNameCommand : public Command {
 public:
  explicit SetChannelNameCommand(const std::shared_ptr<SetChannelNameUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<SetChannelNameUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_SETCHANNELNAMEUSECASE_H_
