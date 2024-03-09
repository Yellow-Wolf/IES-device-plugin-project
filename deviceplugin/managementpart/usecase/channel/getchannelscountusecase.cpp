#include "getchannelscountusecase.h"
#include "deviceplugin/consts.h"

#include <QDebug>

GetChannelsCountUseCase::GetChannelsCountUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                                 const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                                 QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

GetChannelsCountUseCaseResponse GetChannelsCountUseCase::execute(GetChannelsCountUseCaseRequest request) {
  GetChannelsCountUseCaseResponse response{};

  if (_device_entity != nullptr) {

   response.error_code = SUCCESS;
   response.result = CHANNEL_COUNT;
  }

  return response;
}

GetChannelsCountCommand::GetChannelsCountCommand(const std::shared_ptr<GetChannelsCountUseCase> &use_case) :
    _use_case(use_case) {

}

QVariant GetChannelsCountCommand::execute(QVariant request) {
  QVariant result;

  if (_use_case != nullptr) {
    GetChannelsCountUseCaseRequest uc_request{};
    auto uc_response = _use_case->execute(uc_request);

    if (uc_response.error_code == SUCCESS) {
      result = uc_response.result;
    }
  }

  return result;
}
