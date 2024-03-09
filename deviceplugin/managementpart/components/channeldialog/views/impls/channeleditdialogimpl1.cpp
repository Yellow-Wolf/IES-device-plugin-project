#include "channeleditdialogimpl1.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#include <widgets/common/basic/standardbutton.h>

#include <QDebug>


ChannelEditDialogImpl1::ChannelEditDialogImpl1(QWidget *parent) : ChannelEditDialog(parent) {
  _data = std::make_shared<DeviceViewData>();

  initUI();
  setConnections();
}

void ChannelEditDialogImpl1::initUI() {
  auto main_layout = new QVBoxLayout(this);
  auto settings_layout = new QHBoxLayout();
  auto buttons_layout = new QHBoxLayout();

  // TODO: Перенести создание виджетов в фабрики
  _channel_settings = std::make_shared<FullChannelSettings>(START_NAMES, false);

  main_layout->addWidget(_channel_settings.get());
}

void ChannelEditDialogImpl1::setConnections() {
  if (_channel_settings != nullptr) {
    QObject::connect(_channel_settings.get(), &FullChannelSettings::onStatusChanged,
                     this, &ChannelEditDialogImpl1::enabledChangedBridgeSlot);

    QObject::connect(_channel_settings.get(), &FullChannelSettings::writeDelayButtonClicked,
                     this, &ChannelEditDialogImpl1::delayChangedBridgeSlot);
  }
}

void ChannelEditDialogImpl1::setChannelData(const std::shared_ptr<ChannelViewData> &data) {
//  _data = data;

}

void ChannelEditDialogImpl1::setChannelNum(int num) {
  setWindowTitle(_dialog_name_prefix + QString::number(num));
  _channel_num = num;

  if (isChannelValid(_channel_num)) {
    if (_channel_settings != nullptr) {
      auto channel_view_data = _data->channels_data[_channel_num];
      _channel_settings->updateChannelSettings(channel_view_data);
    }
  }
}

void ChannelEditDialogImpl1::setChannelName(const QString &value) {
  if (_channel_settings != nullptr) {
    _channel_settings->setChannelName(value);
  }
}

void ChannelEditDialogImpl1::setChannelDelay(uint64_t value) {
  if (_channel_settings != nullptr) {
    _channel_settings->setChannelDelay(value);
  }
}

void ChannelEditDialogImpl1::setChannelWidth(uint64_t value) {
  if (_channel_settings != nullptr) {
    _channel_settings->setChannelWidth(value);
  }
}

void ChannelEditDialogImpl1::setChannelEnabled(bool enabled) {
  if (_channel_settings != nullptr) {
    _channel_settings->setOnButtonState(enabled);
  }
}

void ChannelEditDialogImpl1::setChannelInverted(bool inverted) {
  if (_channel_settings != nullptr) {
    _channel_settings->setInvButtonState(inverted);
  }
}

void ChannelEditDialogImpl1::setChannelStartSource(uint16_t value) {
  if (_channel_settings != nullptr) {
    _channel_settings->setStartSource(value);
  }
}

void ChannelEditDialogImpl1::setChannelStartMode(ChannelMode value) {
  if (_channel_settings != nullptr) {
    switch (value) {
      case START:
        _channel_settings->setFromStartMode();
        break;
      case PROXY:
        _channel_settings->setProxyMode();
        break;
    }
  }
}

void ChannelEditDialogImpl1::acceptButtonClickedBridgeSlot() {

}

void ChannelEditDialogImpl1::cancelButtonClickedBridgeSlot() {

}

void ChannelEditDialogImpl1::delayChangedBridgeSlot(uint64_t value) {
  emit channelDelayChanged(_channel_num, value);
}

void ChannelEditDialogImpl1::widthChangedBridgeSlot(uint64_t value) {
  emit channelWidthChanged(_channel_num, value);
}

void ChannelEditDialogImpl1::enabledChangedBridgeSlot(bool value) {
  emit channelEnabledChanged(_channel_num, value);
}

void ChannelEditDialogImpl1::invertedChangedBridgeSlot(bool value) {
  emit channelInvertedChanged(_channel_num, value);
}

void ChannelEditDialogImpl1::startModeChangedBridgeSlot(uint16_t value) {
  emit channelStartModeChanged(_channel_num, value);
}

void ChannelEditDialogImpl1::startSourceChangedBridgeSlot(uint16_t value) {
  emit channelStartSourceChanged(_channel_num, value);
}

bool ChannelEditDialogImpl1::isChannelValid(int channel_num) {
  bool result = false;

  if (_data != nullptr) {
    if (channel_num >= 0 && channel_num < _data->channels_data.size()) {
      result = true;
    }
  }

  return result;
}


void ChannelEditDialogImpl1::setChannelName(int channel_num, const QString &value) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].channel_name = value;
    }

    if (_channel_num == channel_num) {
      setChannelName(value);
    }
  }
}

void ChannelEditDialogImpl1::setChannelDelay(int channel_num, uint64_t value) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].channel_delay_value = value;
    }

    if (_channel_num == channel_num) {
      setChannelDelay(value);
    }
  }
}

void ChannelEditDialogImpl1::setChannelWidth(int channel_num, uint64_t value) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].channel_width_value = value;
    }

    if (_channel_num == channel_num) {
      setChannelWidth(value);
    }
  }
}

void ChannelEditDialogImpl1::setChannelEnabled(int channel_num, bool enabled) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].enabled_status = enabled;
    }

    if (_channel_num == channel_num) {
      setChannelEnabled(enabled);
    }
  }
}

void ChannelEditDialogImpl1::setChannelInverted(int channel_num, bool inverted) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].inverted_status = inverted;
    }

    if (_channel_num == channel_num) {
      setChannelInverted(inverted);
    }
  }
}

void ChannelEditDialogImpl1::setChannelStartSource(int channel_num, uint16_t value) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].start_source_value = value;
    }

    if (_channel_num == channel_num) {
      setChannelStartSource(value);
    }
  }
}

void ChannelEditDialogImpl1::setChannelStartMode(int channel_num, ChannelMode value) {
  if (isChannelValid(channel_num)) {
    if (_data != nullptr) {
      _data->channels_data[channel_num].start_mode_value = value;
    }

    if (_channel_num == channel_num) {
      setChannelStartMode(value);
    }
  }
}
