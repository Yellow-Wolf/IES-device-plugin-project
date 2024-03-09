#include "getchannelnameusecase.h"

#include <QDebug>

GetChannelNameUseCase::GetChannelNameUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                             const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                             QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

GetChannelNameUseCaseResponse GetChannelNameUseCase::execute(GetChannelNameUseCaseRequest request) {
  GetChannelNameUseCaseResponse response{};

  int channel_num = request.channel_num;

  if (_device_entity != nullptr) {
    GetChannelNameRequest entity_request{channel_num};
    auto entity_response = _device_entity->getChannelName(entity_request);
    response.error_code = entity_response.error_code;

    if (response.error_code == SUCCESS) {
      response.channel_name = QString::fromStdString(entity_response.result);
      if (_device_entity_poll != nullptr) {
        _device_entity_poll->channelNamesPoll();
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

GetChannelNameCommand::GetChannelNameCommand(const std::shared_ptr<GetChannelNameUseCase> &use_case) :
    _use_case(use_case) {

}

QVariant GetChannelNameCommand::execute(QVariant request) {
  QVariant result;

  if (_use_case != nullptr) {
    bool is_ok;
    int channel_num = request.toInt(&is_ok);
    if (is_ok) {
      GetChannelNameUseCaseRequest uc_request{channel_num};
      auto uc_response = _use_case->execute(uc_request);

      if (uc_response.error_code == SUCCESS) {
        result = uc_response.channel_name;
        qDebug() << "Result command in channel name is " << result << " " << __func__;
      } else {
        qCritical() << "Error occured while execution of get channel name usecase in its command " << __func__;
      }
    } else {
      qCritical() << "Error while casting qvariant to channel num is get channel name command " << __func__;
    }
  }

  return result;
}