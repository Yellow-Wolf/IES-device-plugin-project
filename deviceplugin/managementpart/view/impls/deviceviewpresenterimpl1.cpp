#include "deviceviewpresenterimpl1.h"

#include <QDebug>


DeviceViewPresenterImpl1::DeviceViewPresenterImpl1(const std::shared_ptr<DeviceViewData> &data,
                                                   QObject *parent):
                                                   DeviceViewPresenter(parent),
                                                   _data(data) {

}

bool DeviceViewPresenterImpl1::isInnerStartPeriodEnabled() {
  auto result = false;

  if (_data != nullptr) {
    result = _data->inner_start_period_enabled;
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }

  return result;
}

void DeviceViewPresenterImpl1::setInnerStartPeriodEnabled(bool enabled) {
  if (_data != nullptr) {
    _data->inner_start_period_enabled = enabled;
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }
}

uint64_t DeviceViewPresenterImpl1::getInnerStartPeriod() {
  uint64_t result = 0;

  if (_data != nullptr) {
    result = _data->inner_start_period_value;
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }

  return result;
}

void DeviceViewPresenterImpl1::setInnerStartPeriod(uint64_t value) {
  if (_data != nullptr) {
    _data->inner_start_period_value = value;
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }
}

bool DeviceViewPresenterImpl1::isChannelEnabledEnabled(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelEnabledEnabled(int channel_num, bool enabled) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].enabled_enabled = enabled;
    }
  }
}

bool DeviceViewPresenterImpl1::isChannelEnabledVisible(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelEnabledVisible(int channel_num, bool visible) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].enabled_visible = visible;
    }
  }
}

bool DeviceViewPresenterImpl1::getChannelEnabledValue(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelEnabledValue(int channel_num, bool value) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].enabled_status = value;
    }
  }
}

bool DeviceViewPresenterImpl1::isChannelDelayEnabled(int channel_num) {
  auto result = false;

  if (_data != nullptr) {

    if (channel_num >= 0 && channel_num < _data->channels_data.count()) {
      result = _data->channels_data[channel_num].is_channel_delay_enabled;
    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }

  return result;
}

void DeviceViewPresenterImpl1::setChannelDelayEnabled(int channel_num, bool enabled) {
  if (_data != nullptr) {

    if (channel_num >= 0 && channel_num < _data->channels_data.count()) {
      _data->channels_data[channel_num].is_channel_delay_enabled = enabled;
    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }

}

uint64_t DeviceViewPresenterImpl1::getChannelDelayValue(int channel_num) {
  uint64_t result = 0;

  if (_data != nullptr) {

    if (channel_num >= 0 && channel_num < _data->channels_data.count()) {
      result = _data->channels_data[channel_num].channel_delay_value;
    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }

  return result;
}

void DeviceViewPresenterImpl1::setChannelDelayValue(int channel_num, uint64_t value) {
  if (_data != nullptr) {

    if (channel_num >= 0 && channel_num < _data->channels_data.count()) {
      _data->channels_data[channel_num].channel_delay_value = value;
    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  } else {
    qWarning() << "Data for presenter is nullptr " << __func__;
  }

}

std::shared_ptr<ChannelViewData> DeviceViewPresenterImpl1::getChannelData(int channel_num) {
  std::shared_ptr<ChannelViewData> result = nullptr;

  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      result = std::shared_ptr<ChannelViewData>(&_data->channels_data[channel_num]);
    }
  }

  return result;
}

bool DeviceViewPresenterImpl1::isChannelValid(int channel_num) {
  bool result = false;

  if (_data != nullptr) {
    if (channel_num >= 0 && channel_num < _data->channels_data.size()) {
      result = true;
    }
  }

  return result;
}

bool DeviceViewPresenterImpl1::isInnerStartWidthEnabled() {
  return false;
}

void DeviceViewPresenterImpl1::setInnerStartWidthEnabled(bool enabled) {

}

uint64_t DeviceViewPresenterImpl1::getInnerStartWidth() {
  return 0;
}

void DeviceViewPresenterImpl1::setInnerStartWidth(uint64_t value) {

}

bool DeviceViewPresenterImpl1::isInnerStartEnabledStatusEnabled() {
  return false;
}

void DeviceViewPresenterImpl1::setInnerStartEnabledStatusEnabled(bool enabled) {

}

uint64_t DeviceViewPresenterImpl1::getInnerStartEnabledStatus() {
  return 0;
}

void DeviceViewPresenterImpl1::setInnerStartEnabledStatus(bool value) {

}

bool DeviceViewPresenterImpl1::isInnerStartInvertedStatusEnabled() {
  return false;
}

void DeviceViewPresenterImpl1::setInnerStartInvertedStatusEnabled(bool enabled) {

}

uint64_t DeviceViewPresenterImpl1::getInnerStartInvertedStatus() {
  return 0;
}

void DeviceViewPresenterImpl1::setInnerStartInvertedStatus(bool value) {

}

bool DeviceViewPresenterImpl1::isChannelWidthEnabled(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelWidthEnabled(int channel_num, bool enabled) {

}

uint64_t DeviceViewPresenterImpl1::getChannelWidthValue(int channel_num) {
  return 0;
}

void DeviceViewPresenterImpl1::setChannelWidthValue(int channel_num, uint64_t value) {

}

bool DeviceViewPresenterImpl1::isChannelEnabledStatusEnabled(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelEnabledStatusEnabled(int channel_num, bool enabled) {

}

bool DeviceViewPresenterImpl1::getChannelEnabledStatusValue(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelEnabledStatusValue(int channel_num, bool value) {

}

bool DeviceViewPresenterImpl1::isChannelInvertedStatusEnabled(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelInvertedStatusEnabled(int channel_num, bool enabled) {

}

bool DeviceViewPresenterImpl1::getChannelInvertedStatusValue(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelInvertedStatusValue(int channel_num, bool value) {

}

bool DeviceViewPresenterImpl1::isChannelStartSourceEnabled(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelStartSourceEnabled(int channel_num, bool enabled) {

}

uint16_t DeviceViewPresenterImpl1::getChannelStartSourceValue(int channel_num) {
  return 0;
}

void DeviceViewPresenterImpl1::setChannelStartSourceValue(int channel_num, uint16_t value) {

}

bool DeviceViewPresenterImpl1::isChannelStartModeEnabled(int channel_num) {
  return false;
}

void DeviceViewPresenterImpl1::setChannelStartModeEnabled(int channel_num, bool enabled) {

}

ChannelMode DeviceViewPresenterImpl1::getChannelStartModeValue(int channel_num) {
  return PROXY;
}

void DeviceViewPresenterImpl1::setChannelStartModeValue(int channel_num, ChannelMode value) {

}
