#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELINVERTEDSTATUSUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELINVERTEDSTATUSUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct SetChannelInvertedStatusUseCaseRequest {

};

struct SetChannelInvertedStatusUseCaseResponse {
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class SetChannelInvertedStatusUseCase : public QObject {
 Q_OBJECT
 public:
  explicit SetChannelInvertedStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                           const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                           QObject *parent = nullptr);

  SetChannelInvertedStatusUseCaseResponse execute(SetChannelInvertedStatusUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class SetChannelInvertedStatusCommand : public Command {
 public:
  explicit SetChannelInvertedStatusCommand(const std::shared_ptr<SetChannelInvertedStatusUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<SetChannelInvertedStatusUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_SETCHANNELINVERTEDSTATUSUSECASE_H_
