#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELINVERTEDSTATUSUSECASE_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELINVERTEDSTATUSUSECASE_H_

#include <memory>

#include <QObject>
#include <plugin/deviceplugins/commandprovider.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/callbacksubscriptions/ideviceentitypoll.h"

struct GetChannelInvertedStatusUseCaseRequest {
  int channel_num;
};

struct GetChannelInvertedStatusUseCaseResponse {
  bool value = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

class GetChannelInvertedStatusUseCase : public QObject {
 Q_OBJECT
 public:
  explicit GetChannelInvertedStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                           const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                           QObject *parent = nullptr);

  GetChannelInvertedStatusUseCaseResponse execute(GetChannelInvertedStatusUseCaseRequest request);

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;
};

class GetChannelInvertedStatusCommand : public Command {
 public:
  explicit GetChannelInvertedStatusCommand(const std::shared_ptr<GetChannelInvertedStatusUseCase> &use_case);

  QVariant execute(QVariant request) override;

 private:
  std::shared_ptr<GetChannelInvertedStatusUseCase> _use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_CHANNEL_GETCHANNELINVERTEDSTATUSUSECASE_H_
