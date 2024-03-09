#include "getchannelinvertedstatususecase.h"

#include <QDebug>

GetChannelInvertedStatusUseCase::GetChannelInvertedStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                                                 const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                                                 QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

GetChannelInvertedStatusUseCaseResponse GetChannelInvertedStatusUseCase::execute(GetChannelInvertedStatusUseCaseRequest request) {
  GetChannelInvertedStatusUseCaseResponse response{};

  auto channel_num = request.channel_num;

  if (_device_entity != nullptr) {

    GetChannelInvertedStatusRequest entity_request{channel_num};
    auto entity_response = _device_entity->getChannelsInvertedStatus(entity_request);
    response.error_code = entity_response.error_code;

    if (response.error_code == SUCCESS) {
      response.value = entity_response.result;
      if (_device_entity_poll != nullptr) {
        _device_entity_poll->channelInvertedStatusesPoll();
      } else {
        qCritical() << "Device entity poll is nullptr " << __func__;
      }
    } else {
      qCritical() << "Error code after set channel inverted status is not SUCCESS " << response.error_code << " "
                  << __func__;
    }
  }

  return response;
}

GetChannelInvertedStatusCommand::GetChannelInvertedStatusCommand(const std::shared_ptr<GetChannelInvertedStatusUseCase> &use_case)
    :
    _use_case(use_case) {

}

QVariant GetChannelInvertedStatusCommand::execute(QVariant request) {
  QVariant result;

  bool is_ok = false;
  auto channel_num = request.toInt(&is_ok);
  if (is_ok) {
    if (_use_case != nullptr) {
      GetChannelInvertedStatusUseCaseRequest uc_request{channel_num};
      auto uc_response = _use_case->execute(uc_request);

      if (uc_response.error_code == SUCCESS) {
        result = uc_response.value;
      }
    }

  } else {
    qCritical() << "Invalid request from Command  QVariant should be int: " << request << __func__;
  }

  return result;
}