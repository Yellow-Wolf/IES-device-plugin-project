#include "deviceentityconnectedstatestandaloneimpl1.h"
#include "deviceplugin/consts.h"

#include <QDebug>
#include <iostream>


DeviceEntityConnectedStateStandaloneImpl1::DeviceEntityConnectedStateStandaloneImpl1(const std::shared_ptr<DeviceEntity> &device_entity,
                                                                                     const std::shared_ptr<DeviceEntityRegCard> &reg_card,
                                                                                     const std::shared_ptr<DeviceEntityRegCard> &postponed_reg_card):
 _reg_card(reg_card),
 _postponed_reg_card(postponed_reg_card),
 _device_entity(device_entity) {

}

GetChannelDelayResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsDelay(GetChannelDelayRequest request) {
  GetChannelDelayResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsDelay(request);
  }

  return response;
}

int DeviceEntityConnectedStateStandaloneImpl1::getChannelCount() {
  return CHANNEL_COUNT;
}

GetSyncModuleStatusesResponse DeviceEntityConnectedStateStandaloneImpl1::getSyncModuleStatuses(
    GetSyncModuleStatusesRequest request) {
  GetSyncModuleStatusesResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getSyncModuleStatuses(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }


  return response;
}

GetSFPParametersResponse DeviceEntityConnectedStateStandaloneImpl1::getSFPParameters(GetSFPParametersRequest request) {
  GetSFPParametersResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getSFPParameters(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }


  return response;
}

GetChannelWidthResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsWidth(GetChannelWidthRequest request) {
  GetChannelWidthResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsWidth(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }


  return response;
}

GetChannelEnabledStatusResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsEnabledStatus(
    GetChannelEnabledStatusRequest request) {
  GetChannelEnabledStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsEnabledStatus(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}

GetChannelInvertedStatusResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsInvertedStatus(
    GetChannelInvertedStatusRequest request) {
  GetChannelInvertedStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsInvertedStatus(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}

GetChannelStartModeResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsStartMode(GetChannelStartModeRequest request) {
  GetChannelStartModeResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsStartMode(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}

GetChannelStartSourceResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsStartSource(
    GetChannelStartSourceRequest request) {
  GetChannelStartSourceResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsStartSource(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}

SetChannelDelayResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelDelay(SetChannelDelayRequest request) {
  SetChannelDelayResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelDelay(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}
SetChannelWidthResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelWidth(SetChannelWidthRequest request) {
  return SetChannelWidthResponse();
}
SetChannelEnabledStatusResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelEnabledStatus(
    SetChannelEnabledStatusRequest request) {
  SetChannelEnabledStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelEnabledStatus(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}
SetChannelInvertedStatusResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelInvertedStatus(
    SetChannelInvertedStatusRequest request) {
  SetChannelInvertedStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelInvertedStatus(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}
SetChannelStartSourceResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelStartSource(
    SetChannelStartSourceRequest request) {
  SetChannelStartSourceResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelStartSource(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}

SetChannelStartModeResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelStartMode(SetChannelStartModeRequest request) {
  SetChannelStartModeResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelStartMode(request);
  } else {
    qCritical() << "Reg card is nullptr " << __func__;
  }

  return response;
}

ErrorCode DeviceEntityConnectedStateStandaloneImpl1::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  // TODO: В мобдас враппере добавить функционал отложенной множественной записи. Чтобы можно было писать много регистров за раз из массива, который заполняется постепенно
  //  Как вариант, можно написать ещё одну обертку modbus, где это будет реализовано

  ErrorCode result = OPERATION_INTERRUPTED;
  std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
  if (dto != nullptr && _postponed_reg_card != nullptr && _device_entity != nullptr) {
    auto device_name = dto->name;
    _device_entity->setDeviceName(device_name);

    auto device_description = dto->description;
    _device_entity->setDeviceDescription(device_description);


    auto &channels_data = dto->channels;
    for (int i = 0; i < channels_data.size(); i++) {
      auto set_channel_name_response = _device_entity->setChannelName({i, channels_data[i].channel_name});
      result = set_channel_name_response.error_code;
      qDebug() << "Channel name write result " << result;

     auto set_channel_delay_response = _postponed_reg_card->setChannelDelay({i, channels_data[i].channel_delay});
     result = set_channel_delay_response.error_code;
      qDebug() << "Channel delay write result " << result;
//     if (result != SUCCESS) return result;

//     auto set_channel_width_response = setChannelWidth({i, channels_data[i].channel_width});
//     result = set_channel_width_response.error_code;
//      qDebug() << "Channel width write result " << result;
//     if (result != SUCCESS) return result;


     auto set_channel_enabled_response = _postponed_reg_card->setChannelEnabledStatus({i, channels_data[i].channel_enabled});
     result = set_channel_enabled_response.error_code;
      qDebug() << "Channel enabled status write result " << result << "\tchannel num: " << i << ", channel_enabled: " << channels_data[i].channel_enabled;
//     if (result != SUCCESS) return result;

     auto set_channel_inverted_response = _postponed_reg_card->setChannelInvertedStatus({i, channels_data[i].channel_inverted});
     result = set_channel_inverted_response.error_code;
      qDebug() << "Channel inverted status write result " << result;
//     if (result != SUCCESS) return result;
//

      auto set_channel_start_source = _postponed_reg_card->setChannelStartSource({i, channels_data[i].channel_start_source});
      result = set_channel_start_source.error_code;
      qDebug() << "Channel start source write result " << result;
////     if (result != SUCCESS) return result;
//
     auto set_channel_start_mode_response = _postponed_reg_card->setChannelStartMode({i, channels_data[i].channel_mode});
     result = set_channel_start_mode_response.error_code;
      qDebug() << "Channel start mode write result " << result;
//     if (result != SUCCESS) return result;
    }

    _postponed_reg_card->updateRegCard();
  }
  return result;
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityConnectedStateStandaloneImpl1::updateDeviceDTO() {
  // TODO: Дописать процесс формирования DTO
  return DeviceEntityState::updateDeviceDTO();
}

GetInnerStartPeriodResponse DeviceEntityConnectedStateStandaloneImpl1::getInnerStartPeriod(GetInnerStartPeriodRequest request) {
    GetInnerStartPeriodResponse response;

    if (_reg_card != nullptr) {
        response = _reg_card->getInnerStartPeriod(request);
    }

    return response;
}