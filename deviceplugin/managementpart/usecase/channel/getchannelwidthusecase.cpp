#include "getchannelwidthusecase.h"

#include <QDebug>

GetChannelWidthUseCase::GetChannelWidthUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                               const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                               QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

GetChannelWidthUseCaseResponse GetChannelWidthUseCase::execute(GetChannelWidthUseCaseRequest request) {
  GetChannelWidthUseCaseResponse response{};

  auto channel_num = request.channel_num;

  if (_device_entity != nullptr) {

    GetChannelWidthRequest entity_request{channel_num};
    auto entity_response = _device_entity->getChannelsWidth(entity_request);
    response.error_code = entity_response.error_code;

    if (response.error_code == SUCCESS) {
      response.value = entity_response.result;
      if (_device_entity_poll != nullptr) {
        _device_entity_poll->channelWidthsPoll();
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

GetChannelWidthCommand::GetChannelWidthCommand(const std::shared_ptr<GetChannelWidthUseCase> &use_case) :
    _use_case(use_case) {

}

QVariant GetChannelWidthCommand::execute(QVariant request) {
  QVariant result;

  bool is_ok = false;
  auto channel_num = request.toInt(&is_ok);
  if (is_ok) {
    if (_use_case != nullptr) {
      GetChannelWidthUseCaseRequest uc_request{channel_num};
      auto uc_response = _use_case->execute(uc_request);

      if (uc_response.error_code == SUCCESS) {
        result = uc_response.value;
      }
    }
  }

  return result;
}
