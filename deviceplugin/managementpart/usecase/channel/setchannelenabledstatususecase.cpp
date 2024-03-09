#include "setchannelenabledstatususecase.h"

#include <QDebug>

SetChannelEnabledStatusUseCase::SetChannelEnabledStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                                               const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                                               QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

SetChannelEnabledStatusUseCaseResponse SetChannelEnabledStatusUseCase::execute(SetChannelEnabledStatusUseCaseRequest request) {
  SetChannelEnabledStatusUseCaseResponse response{};

  int channel_num = request.channel_num;
  bool value = request.value;

  if (_device_entity != nullptr) {
    SetChannelEnabledStatusRequest entity_request{channel_num, value};
    auto entity_response = _device_entity->setChannelEnabledStatus(entity_request);
    response.error_code = entity_response.error_code;

    if (response.error_code == SUCCESS) {
      response.value = entity_response.value;
      if (_device_entity_poll != nullptr) {
        _device_entity_poll->channelEnabledStatusesPoll();
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

SetChannelEnabledStatusCommand::SetChannelEnabledStatusCommand(const std::shared_ptr<SetChannelEnabledStatusUseCase> &use_case)
    :
    _use_case(use_case) {

}

QVariant SetChannelEnabledStatusCommand::execute(QVariant request) {
  QVariant result;

  if (_use_case != nullptr) {
    SetChannelEnabledStatusUseCaseRequest uc_request{};
    auto uc_response = _use_case->execute(uc_request);
    // TODO: TO IMPLEMENT
  }

  return result;
}