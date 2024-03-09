#include "setchannelnameusecase.h"

#include <QDebug>

SetChannelNameUseCase::SetChannelNameUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                             const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                             QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

SetChannelNameUseCaseResponse SetChannelNameUseCase::execute(SetChannelNameUseCaseRequest request) {
  SetChannelNameUseCaseResponse response{};

  int channel_num = request.channel_num;
  auto channel_name = request.channel_name;

  if (_device_entity != nullptr) {
    SetChannelNameRequest entity_request{channel_num, channel_name.toStdString()};
    auto entity_response = _device_entity->setChannelName(entity_request);
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

SetChannelNameCommand::SetChannelNameCommand(const std::shared_ptr<SetChannelNameUseCase> &use_case) :
    _use_case(use_case) {

}

QVariant SetChannelNameCommand::execute(QVariant request) {
  QVariant result;

  if (_use_case != nullptr) {
    SetChannelNameUseCaseRequest uc_request{};
    auto uc_response = _use_case->execute(uc_request);
    // TODO: TO IMPLEMENT
  }

  return result;
}