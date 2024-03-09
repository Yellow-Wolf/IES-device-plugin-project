#include "setchannelstartsourceusecase.h"

#include <QDebug>

SetChannelStartSourceUseCase::SetChannelStartSourceUseCase(const std::shared_ptr<DeviceEntity> &device_entity,
                                                           const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                                                           QObject *parent) :
    QObject(parent),
    _device_entity(device_entity),
    _device_entity_poll(device_entity_poll) {

}

SetChannelStartSourceUseCaseResponse SetChannelStartSourceUseCase::execute(SetChannelStartSourceUseCaseRequest request) {
  SetChannelStartSourceUseCaseResponse response{};

  // TODO: TO IMPLEMENT

  if (_device_entity != nullptr) {

    if (response.error_code == SUCCESS) {
      if (_device_entity_poll != nullptr) {

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

SetChannelStartSourceCommand::SetChannelStartSourceCommand(const std::shared_ptr<SetChannelStartSourceUseCase> &use_case)
    :
    _use_case(use_case) {

}

QVariant SetChannelStartSourceCommand::execute(QVariant request) {
  QVariant result;

  if (_use_case != nullptr) {
    SetChannelStartSourceUseCaseRequest uc_request{};
    auto uc_response = _use_case->execute(uc_request);
    // TODO: TO IMPLEMENT
  }

  return result;
}