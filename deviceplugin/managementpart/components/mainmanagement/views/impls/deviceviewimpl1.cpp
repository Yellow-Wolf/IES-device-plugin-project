#include "deviceviewimpl1.h"
#include "deviceplugin/consts.h"


#include "deviceplugin/entity/devicetypes.h"
#include "deviceplugin/widgets/t831/channelsbox/channelscount8strategy.h"

#include <QGridLayout>

#include <QTabWidget>

DeviceViewImpl1::DeviceViewImpl1(const QString &caption, QWidget *parent):
 DeviceView(parent) {
  _device_view_data = std::make_shared<DeviceViewData>();

  initUI(caption);
  setConnections();
}

void DeviceViewImpl1::initUI(const QString &caption) {
  auto *main_layout = new QVBoxLayout(this);
  auto *upper_statuses_layout = new QHBoxLayout;
  auto *channels_layout = new QGridLayout;
  auto *lt = new QGridLayout;

  _sync_sfp_statuses_widget = new SFPStatusesDialog(this);


  _sync_module_widget = new SyncModuleWidget("SYNC", this);
  _inner_start_settings_widget = new InnerStartSettingsWidget(this);
  _channel_settings = new FullChannelSettings(START_NAMES, false, this);

  auto channels_count_strategy_ = new ChannelsCount8Strategy();
  _channels_box = new ChannelsBoxV2(channels_count_strategy_, this);
  _channels_box->setTitle("");

  auto *channel_tab_widget = new QTabWidget(this);
  channel_tab_widget->addTab(_channels_box, tr("Кнопочное представление"));

  channels_layout->addWidget(_channel_settings, 0, 0, 2, 1);
  channels_layout->addWidget(channel_tab_widget, 0, 1);
  _add_delay_for_group_of_channels_button = new StandardButton("Добавить задержку группе каналов", this);
  channels_layout->addWidget(_add_delay_for_group_of_channels_button, 1, 1);

  upper_statuses_layout->addWidget(_sync_module_widget);
  upper_statuses_layout->addWidget(_inner_start_settings_widget);
  upper_statuses_layout->addStretch(1);

  /*auto b = new InnerStartSettingsWidget(this);
  lt->addWidget(b);*/

  main_layout->addLayout(upper_statuses_layout);
  main_layout->addLayout(channels_layout);

  //main_layout->addLayout(lt);

}

void DeviceViewImpl1::setConnections() {
  if (_inner_start_settings_widget != nullptr) {
    QObject::connect(_inner_start_settings_widget, &InnerStartSettingsWidget::writePeriodButtonClicked,
                     this, &DeviceViewImpl1::innerStartPeriodChangedSlot);

    QObject::connect(_inner_start_settings_widget, &InnerStartSettingsWidget::writeWidthButtonClicked,
                     this, &DeviceViewImpl1::innerStartWidthChangedSlot);

    QObject::connect(_inner_start_settings_widget, &InnerStartSettingsWidget::onStatusChanged,
                     this, &DeviceViewImpl1::innerStartEnabledStatusChangedSlot);

    QObject::connect(_inner_start_settings_widget, &InnerStartSettingsWidget::invStatusChanged,
                     this, &DeviceViewImpl1::innerStartInvertedStatusChangedSlot);
  }

  if (_sync_module_widget != nullptr) {
    QObject::connect(_sync_module_widget, &SyncModuleWidget::getSFPParamsSignal,
                     this, &DeviceViewImpl1::syncSFPOpenParamsSlot);
  }

  if (_channels_box != nullptr) {
    QObject::connect(_channels_box, &ChannelsBoxV2::channelChosenActionSignal,
                     this, &DeviceViewImpl1::currentChannelChangedBridgeSlot);
  }

  if (_channel_settings != nullptr) {
    QObject::connect(_channel_settings, &FullChannelSettings::onStatusChanged,
                     this, &DeviceViewImpl1::channelEnabledStatusChangedBridgeSlot);

    QObject::connect(_channel_settings, &FullChannelSettings::channelNameChangedSignal,
                     this, &DeviceViewImpl1::channelNameChangedBridgeSlot);
  }
}

void DeviceViewImpl1::setInnerStartPeriod(uint64_t value) {
  if (_device_view_data != nullptr) {
    _device_view_data->inner_start_period_value = value;

    if (_inner_start_settings_widget != nullptr) {
      _inner_start_settings_widget->setInnerStartPeriod(value);
    }
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setChannelDelay(int channel_num, uint64_t value) {
  if (_device_view_data != nullptr) {
    auto &channels_data = _device_view_data->channels_data;
    if (channel_num >= 0 && channel_num < channels_data.count()) {
      channels_data[channel_num].channel_delay_value = value;

      if (_channel_settings != nullptr && _channels_box != nullptr) {
        if (channel_num == _channels_box->getCurrentChannelNum()) {
          _channel_settings->setChannelDelay(value);
        }
      }

    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  }
}

void DeviceViewImpl1::syncSFPOpenParamsSlot() {
  if (_sync_sfp_statuses_widget != nullptr) {
    _sync_sfp_statuses_widget->show();
  } else {
    qCritical() << "CANNOT OPEN SYNC SFP MODULE STATUSES nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncSFPTemp(double value) {
  if (_device_view_data != nullptr) {
    auto &sfp_view_data = _device_view_data->sync_sfp_data;
    sfp_view_data.temp = QString::number(value);

    if (_sync_sfp_statuses_widget != nullptr) {
      auto value_string = QString::number(value);
      _sync_sfp_statuses_widget->setTemp(value_string);
    } else {
      qWarning() << "SFP statuses widget is nullptr " << __func__;
    }

    qDebug() << "Sync SFP value " << value << " " << __func__;
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncSFPTxVoltage(double value) {
  if (_device_view_data != nullptr) {
    auto &sfp_view_data = _device_view_data->sync_sfp_data;
    sfp_view_data.tx_voltage = QString::number(value);

    if (_sync_sfp_statuses_widget != nullptr) {
      auto value_string = QString::number(value);
      _sync_sfp_statuses_widget->setTxVoltage(value_string);
    } else {
      qWarning() << "SFP statuses widget is nullptr " << __func__;
    }

    qDebug() << "Sync SFP value " << value << " " << __func__;
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncSFPTxAmperage(double value) {
  if (_device_view_data != nullptr) {
    auto &sfp_view_data = _device_view_data->sync_sfp_data;
    sfp_view_data.tx_amperage = QString::number(value);

    if (_sync_sfp_statuses_widget != nullptr) {
      auto value_string = QString::number(value);
      _sync_sfp_statuses_widget->setTxAmperage(value_string);
    } else {
      qWarning() << "SFP statuses widget is nullptr " << __func__;
    }

    qDebug() << "Sync SFP value " << value << " " << __func__;
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncSFPTxOpticalPower(double value) {
  if (_device_view_data != nullptr) {
    auto &sfp_view_data = _device_view_data->sync_sfp_data;
    sfp_view_data.tx_optical_power = QString::number(value);

    if (_sync_sfp_statuses_widget != nullptr) {
      auto value_string = QString::number(value);
      _sync_sfp_statuses_widget->setTxOpticalPower(value_string);
    } else {
      qWarning() << "SFP statuses widget is nullptr " << __func__;
    }

    qDebug() << "Sync SFP value " << value << " " << __func__;
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncSFPRxPower(double value) {
  if (_device_view_data != nullptr) {
    auto &sfp_view_data = _device_view_data->sync_sfp_data;
    sfp_view_data.rx_power = QString::number(value);

    if (_sync_sfp_statuses_widget != nullptr) {
      auto value_string = QString::number(value);
      _sync_sfp_statuses_widget->setRxPower(value_string);
    } else {
      qWarning() << "SFP statuses widget is nullptr " << __func__;
    }

    qDebug() << "Sync SFP value " << value << " " << __func__;
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncDesLock(bool value) {
  if (_device_view_data != nullptr) {
    _device_view_data->sync_des_lock = value;

    if (_sync_module_widget != nullptr) {
      _sync_module_widget->setDesLockStatus(value);
    } else {
      qCritical() << "Sync module widget is nullptr " << __func__;
    }
  } else {
    qCritical() << "Device View data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncOscLock(bool value) {
  if (_device_view_data != nullptr) {
    _device_view_data->sync_osc_lock = value;

    if (_sync_module_widget != nullptr) {
      _sync_module_widget->setOscLockStatus(value);
    } else {
      qCritical() << "Sync module widget is nullptr " << __func__;
    }
  } else {
    qCritical() << "Device View data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncRxLoss(bool value) {
  if (_device_view_data != nullptr) {
    _device_view_data->sync_rx_loss = value;

    if (_sync_module_widget != nullptr) {
      _sync_module_widget->setRxLossStatus(value);
    } else {
      qCritical() << "Sync module widget is nullptr " << __func__;
    }
  } else {
    qCritical() << "Device View data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setSyncTxFault(bool value) {
  if (_device_view_data != nullptr) {
    _device_view_data->sync_tx_fault = value;

    if (_sync_module_widget != nullptr) {
      _sync_module_widget->setTxFaultStatus(value);

      qDebug() << "SYNC TX FAULT SET TO " << value << " " << __func__;
    } else {
      qCritical() << "Sync module widget is nullptr " << __func__;
    }
  } else {
    qCritical() << "Device View data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setInnerStartWidth(uint64_t value) {
  if (_device_view_data != nullptr) {
    _device_view_data->inner_start_width_value = value;

    if (_inner_start_settings_widget != nullptr) {
      _inner_start_settings_widget->setInnerStartWidth(value);
    }
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setInnerStartEnabledStatus(bool value) {
  if (_device_view_data != nullptr) {
    _device_view_data->enabled_status = value;

    if (_inner_start_settings_widget != nullptr) {
      _inner_start_settings_widget->setOnButtonState(value);
    } else {
      qCritical() << "Inner start settings widget is nullptr " << __func__;
    }
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setInnerStartInvertedStatus(bool value) {
  if (_device_view_data != nullptr) {
    _device_view_data->inverted_status = value;

    if (_inner_start_settings_widget != nullptr) {
      _inner_start_settings_widget->setInvButtonState(value);
    } else {
      qCritical() << "Inner start settings widget is nullptr " << __func__;
    }
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

void DeviceViewImpl1::setChannelWidth(int channel_num, uint64_t value) {
  if (_device_view_data != nullptr) {
    auto &channels_data = _device_view_data->channels_data;
    if (channel_num >= 0 && channel_num < channels_data.count()) {
      channels_data[channel_num].channel_width_value = value;

      if (_channel_settings != nullptr && _channels_box != nullptr) {
        if (channel_num == _channels_box->getCurrentChannelNum()) {
          _channel_settings->setChannelWidth(value);
        }
      }

    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  }
}

void DeviceViewImpl1::setChannelEnabledStatus(int channel_num, bool value) {
  if (_device_view_data != nullptr) {
    auto &channels_data = _device_view_data->channels_data;
    if (channel_num >= 0 && channel_num < channels_data.count()) {
      channels_data[channel_num].enabled_status = value;

      if (_channel_settings != nullptr && _channels_box != nullptr) {
        _channels_box->setOnButtonState(channel_num, value);
        if (channel_num == _channels_box->getCurrentChannelNum()) {
          _channel_settings->setOnButtonState(value);
        }
      }

    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  }
}

void DeviceViewImpl1::setChannelInvertedStatus(int channel_num, bool value) {
  if (_device_view_data != nullptr) {
    auto &channels_data = _device_view_data->channels_data;
    if (channel_num >= 0 && channel_num < channels_data.count()) {
      channels_data[channel_num].inverted_status = value;

      if (_channel_settings != nullptr && _channels_box != nullptr) {
        _channels_box->setInvButtonState(channel_num, value);
        if (channel_num == _channels_box->getCurrentChannelNum()) {
          _channel_settings->setInvButtonState(value);
        }
      }

    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  }
}

void DeviceViewImpl1::setChannelStartSource(int channel_num, uint16_t value) {
  if (_device_view_data != nullptr) {
    auto &channels_data = _device_view_data->channels_data;
    if (channel_num >= 0 && channel_num < channels_data.count()) {
      channels_data[channel_num].start_source_value = value;

      if (_channel_settings != nullptr && _channels_box != nullptr) {
        if (channel_num == _channels_box->getCurrentChannelNum()) {
          _channel_settings->setStartSource(value);
        }
      }

    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  }
}

void DeviceViewImpl1::setChannelStartMode(int channel_num, uint16_t value) {
  if (_device_view_data != nullptr) {
    auto &channels_data = _device_view_data->channels_data;
    if (channel_num >= 0 && channel_num < channels_data.count()) {
      channels_data[channel_num].start_mode_value = static_cast<ChannelMode>(value);

      if (_channel_settings != nullptr && _channels_box != nullptr) {
        if (channel_num == _channels_box->getCurrentChannelNum()) {

          // TODO: Потом эту логику вынести
          auto mode = static_cast<ChannelMode>(value);
          switch (mode) {
            case START:
              _channel_settings->setFromStartMode();
              break;
            case PROXY:
              _channel_settings->setProxyMode();
              break;
          }

        }
      }

    } else {
      qCritical() << "Channel num " << channel_num << " is incorrect " << __func__;
    }
  }
}

void DeviceViewImpl1::innerStartPeriodChangedSlot(uint64_t value) {
  emit innerStartPeriodChanged(value);
}

void DeviceViewImpl1::innerStartWidthChangedSlot(uint64_t value) {
  emit innerStartWidthChanged(value);
}

void DeviceViewImpl1::innerStartEnabledStatusChangedSlot(bool value) {
  emit innerStartEnabledStatusChanged(value);
}

void DeviceViewImpl1::innerStartInvertedStatusChangedSlot(bool value) {
  emit innerStartInvertedStatusChanged(value);
}

void DeviceViewImpl1::currentChannelChangedBridgeSlot(int channel_num) {

  if (_device_view_data != nullptr) {
    if (channel_num >= 0 && channel_num < _device_view_data->channels_data.size()) {
      auto channel_data = _device_view_data->channels_data[channel_num];

      if (_channel_settings != nullptr) {
        _channel_settings->updateChannelSettings(channel_data);
        _channel_num = channel_num;
      } else {
        qCritical() << "Channel settings is nullptr " << __func__;
      }
    }
  }
}

void DeviceViewImpl1::channelEnabledStatusChangedBridgeSlot(bool value) {
  emit channelEnabledChanged(_channel_num, value);
}

void DeviceViewImpl1::channelNameChangedBridgeSlot(const QString &name) {
  emit channelNameChanged(_channel_num, name);
}

void DeviceViewImpl1::setChannelName(int channel_num, const QString &channel_name) {
  if (_device_view_data != nullptr) {
    auto &channels = _device_view_data->channels_data;
    if (channel_num >= 0 && channel_num < channels.size()) {
      channels[channel_num].channel_name = channel_name;

      if (_channel_settings != nullptr && channel_num == _channel_num) {
        _channel_settings->setChannelName(channel_name);
      }
    } else {
      qCritical() << "Channel num is incorrect " << __func__;
    }
  } else {
    qCritical() << "Device view data is nullptr " << __func__;
  }
}

