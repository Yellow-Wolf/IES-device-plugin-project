#include "getchanneldelayusecase.h"

#include <QDebug>

GetChannelDelayUseCase::GetChannelDelayUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                               const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                               QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

GetChannelDelayUseCaseResponse GetChannelDelayUseCase::execute(GetChannelDelayUseCaseRequest request) {
  GetChannelDelayUseCaseResponse response{};

  if (_device_entity != nullptr) {
    GetChannelDelayRequest entity_request{request.channel_num};
    auto entity_response = _device_entity->getChannelsDelay(entity_request);
    response.error_code = entity_response.error_code;

    if (response.error_code == SUCCESS) {
      response.value = entity_response.result;

    } else {
      qCritical() << "Error code after set channel inverted status is not SUCCESS " << response.error_code << " "
                  << __func__;
    }
  }

  return response;
}

GetChannelDelayCommand::GetChannelDelayCommand(const std::shared_ptr<GetChannelDelayUseCase> &use_case) :
    _use_case(use_case) {

}

QVariant GetChannelDelayCommand::execute(QVariant request) {
  QVariant result;

  if (_use_case != nullptr) {
    bool is_ok = false;
    int channel_num = request.toInt(&is_ok);
    if (is_ok) {
      GetChannelDelayUseCaseRequest uc_request{channel_num};
      auto uc_response = _use_case->execute(uc_request);

      if (uc_response.error_code == SUCCESS) {
        result = uc_response.value;
      } else {
        qCritical() << "Use case returned error in get channel delay use case " << __func__;
      }
    } else {
      qCritical() << "Unabled to parse QVariant request to int in get channel delay command " << __func__;
    }
  }

  return result;
}