#include "usecasefactory.h"

#include <QDebug>


UseCaseFactory::UseCaseFactory(const std::shared_ptr<DeviceEntity> &device_entity,
                               const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                               QObject *parent):
                               QObject(parent),
                               _device_entity(device_entity),
                               _device_entity_poll(device_entity_poll) {

}

std::shared_ptr<GetChannelNameUseCase> UseCaseFactory::createGetChannelNameUseCase() {
  if (_get_channel_name_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _get_channel_name_use_case = std::make_shared<GetChannelNameUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _get_channel_name_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channel_name_use_case;
}

std::shared_ptr<GetChannelDelayUseCase> UseCaseFactory::createGetChannelDelayUseCase() {
  if (_get_channel_delay_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll != nullptr) {
      _get_channel_delay_use_case = std::make_shared<GetChannelDelayUseCase>(_device_entity, _device_entity_poll);
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channel_delay_use_case;
}

std::shared_ptr<GetChannelsCountUseCase> UseCaseFactory::createGetChannelsCountUseCase() {
  if (_get_channels_count_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll != nullptr) {
      _get_channels_count_use_case = std::make_shared<GetChannelsCountUseCase>(_device_entity, _device_entity_poll);
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channels_count_use_case;
}

std::shared_ptr<SetChannelEnabledStatusUseCase> UseCaseFactory::createSetChannelEnabledStatusUseCase() {
  if (_set_channel_enabled_status_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _set_channel_enabled_status_use_case = std::make_shared<SetChannelEnabledStatusUseCase>(_device_entity,
                                                                                              _device_entity_poll);
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _set_channel_enabled_status_use_case;
}

std::shared_ptr<GetChannelWidthUseCase> UseCaseFactory::createGetChannelWidthUseCase() {
  if (_get_channel_width_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _get_channel_width_use_case = std::make_shared<GetChannelWidthUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _get_channel_width_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channel_width_use_case;
}

std::shared_ptr<GetChannelEnabledStatusUseCase> UseCaseFactory::createGetChannelEnabledStatusUseCase() {
  if (_get_channel_enabled_status_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _get_channel_enabled_status_use_case =
          std::make_shared<GetChannelEnabledStatusUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _get_channel_enabled_status_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channel_enabled_status_use_case;
}

std::shared_ptr<GetChannelInvertedStatusUseCase> UseCaseFactory::createGetChannelInvertedStatusUseCase() {
  if (_get_channel_inverted_status_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _get_channel_inverted_status_use_case =
          std::make_shared<GetChannelInvertedStatusUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _get_channel_inverted_status_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channel_inverted_status_use_case;
}

std::shared_ptr<GetChannelStartSourceUseCase> UseCaseFactory::createGetChannelStartSourceUseCase() {
  if (_get_channel_start_source_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _get_channel_start_source_use_case =
          std::make_shared<GetChannelStartSourceUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _get_channel_start_source_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channel_start_source_use_case;
}

std::shared_ptr<GetChannelStartModeUseCase> UseCaseFactory::createGetChannelStartModeUseCase() {
  if (_get_channel_start_mode_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _get_channel_start_mode_use_case =
          std::make_shared<GetChannelStartModeUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _get_channel_start_mode_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _get_channel_start_mode_use_case;
}

std::shared_ptr<SetChannelNameUseCase> UseCaseFactory::createSetChannelNameUseCase() {
  if (_set_channel_name_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _set_channel_name_use_case = std::make_shared<SetChannelNameUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _set_channel_name_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _set_channel_name_use_case;
}

std::shared_ptr<SetChannelDelayUseCase> UseCaseFactory::createSetChannelDelayUseCase() {
  if (_set_channel_delay_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _set_channel_delay_use_case = std::make_shared<SetChannelDelayUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _set_channel_delay_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _set_channel_delay_use_case;
}

std::shared_ptr<SetChannelWidthUseCase> UseCaseFactory::createSetChannelWidthUseCase() {
  if (_set_channel_width_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _set_channel_width_use_case = std::make_shared<SetChannelWidthUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _set_channel_width_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _set_channel_width_use_case;
}

std::shared_ptr<SetChannelInvertedStatusUseCase> UseCaseFactory::createSetChannelInvertedStatusUseCase() {
  if (_set_channel_inverted_status_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _set_channel_inverted_status_use_case =
          std::make_shared<SetChannelInvertedStatusUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _set_channel_inverted_status_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _set_channel_inverted_status_use_case;
}

std::shared_ptr<SetChannelStartSourceUseCase> UseCaseFactory::createSetChannelStartSourceUseCase() {
  if (_set_channel_start_source_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _set_channel_start_source_use_case =
          std::make_shared<SetChannelStartSourceUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _set_channel_start_source_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _set_channel_start_source_use_case;
}

std::shared_ptr<SetChannelStartModeUseCase> UseCaseFactory::createSetChannelStartModeUseCase() {
  if (_set_channel_start_mode_use_case == nullptr) {
    if (_device_entity != nullptr && _device_entity_poll) {
      _set_channel_start_mode_use_case = std::make_shared<SetChannelStartModeUseCase>(_device_entity, _device_entity_poll);
      qDebug() << "Usecase _set_channel_start_mode_use_case is successfully created " << __func__;
    } else {
      qWarning() << "Device entity is nullptr " << __func__;
    }
  }

  return _set_channel_start_mode_use_case;
}
