#include "devicecontroller.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelenabledstatususecase.h"

#include <QDebug>


DeviceController::DeviceController(const std::shared_ptr<DeviceView> &test_device_view,
                                   const std::shared_ptr<UseCaseFactory> &use_case_factory,
                                   const std::shared_ptr<DeviceCallbackSubscriptionStandaloneFactory> &device_cb_factory,
                                   QObject *parent) :
    _device_view(test_device_view),
    _use_case_factory(use_case_factory),
    _device_cb_factory(device_cb_factory) {

}

void DeviceController::setConnections() {
  if (_device_cb_factory != nullptr) {
      auto inner_start_period_callback = _device_cb_factory->getInnerStartPeriodCallback();
      if (inner_start_period_callback != nullptr) {
          QObject::connect(inner_start_period_callback.get(), &ULong64ValueCallback::statusChanged,
                           this, &DeviceController::innerStartPeriodModelChangedSlot);
      }

      auto sync_des_lock_callback = _device_cb_factory->getSyncDesLockCallback();
    if (sync_des_lock_callback != nullptr) {
      QObject::connect(sync_des_lock_callback.get(), &BoolValueCallback::statusChanged,
                       this, &DeviceController::syncDesLockModelChangedSlot);
    }

    auto sync_osc_lock_callback = _device_cb_factory->getSyncOscLockCallback();
    if (sync_osc_lock_callback != nullptr) {
      QObject::connect(sync_osc_lock_callback.get(), &BoolValueCallback::statusChanged,
                       this, &DeviceController::syncOscLockModelChangedSlot);
    }

    auto sync_rx_loss_callback = _device_cb_factory->getSyncRxLossCallback();
    if (sync_rx_loss_callback != nullptr) {
      QObject::connect(sync_rx_loss_callback.get(), &BoolValueCallback::statusChanged,
                       this, &DeviceController::syncRxLossModelChangedSlot);
    }

    auto sync_tx_fault_callback = _device_cb_factory->getSyncTxFaultCallback();
    if (sync_tx_fault_callback != nullptr) {
      QObject::connect(sync_tx_fault_callback.get(), &BoolValueCallback::statusChanged,
                       this, &DeviceController::syncTxFaultModelChangedSlot);
    }

    auto sync_sfp_temp_callback = _device_cb_factory->getSyncSFPTempCallback();
    if (sync_sfp_temp_callback != nullptr) {
      QObject::connect(sync_sfp_temp_callback.get(), &DoubleValueCallback::statusChanged,
                       this, &DeviceController::syncSFPTempModelChangedSlot);
    }

    auto sync_sfp_tx_voltage_callback = _device_cb_factory->getSyncSFPTxVoltageCallback();
    if (sync_sfp_tx_voltage_callback != nullptr) {
      QObject::connect(sync_sfp_tx_voltage_callback.get(), &DoubleValueCallback::statusChanged,
                       this, &DeviceController::syncSFPTxVoltageModelChangedSlot);
    }

    auto sync_sfp_tx_amperage_callback = _device_cb_factory->getSyncSFPTxAmperageCallback();
    if (sync_sfp_tx_amperage_callback != nullptr) {
      QObject::connect(sync_sfp_tx_amperage_callback.get(), &DoubleValueCallback::statusChanged,
                       this, &DeviceController::syncSFPTxAmperageModelChangedSlot);
    }

    auto sync_sfp_tx_optical_power_callback = _device_cb_factory->getSyncSFPTxOpticalPowerCallback();
    if (sync_sfp_tx_optical_power_callback != nullptr) {
      QObject::connect(sync_sfp_tx_optical_power_callback.get(), &DoubleValueCallback::statusChanged,
                       this, &DeviceController::syncSFPTxOpticalPowerModelChangedSlot);
    }

    auto sync_sfp_rx_power_callback = _device_cb_factory->getSyncSFPRxPowerCallback();
    if (sync_sfp_rx_power_callback != nullptr) {
      QObject::connect(sync_sfp_rx_power_callback.get(), &DoubleValueCallback::statusChanged,
                       this, &DeviceController::syncSFPRxPowerModelChangedSlot);
    }

    auto channel_delays_callback = _device_cb_factory->getChannelDelaysCallback();
    if (channel_delays_callback != nullptr) {
      QObject::connect(channel_delays_callback.get(), &ULong64ValuesCallback::statusChanged,
                       this, &DeviceController::channelDelaysModelChangedSlot);
      qDebug() << "CHANNEL DELAYS CONNECTED";
    }


    auto channel_names_callback = _device_cb_factory->getChannelNameCallback();
    if (channel_names_callback != nullptr) {
      QObject::connect(channel_names_callback.get(), &StringValuesCallback::statusChanged,
                       this, &DeviceController::channelNameModelChangedSlot);
      qDebug() << "CHANNEL Names CONNECTED";
    }

    auto channel_widths_callback = _device_cb_factory->getChannelWidthsCallback();
    if (channel_widths_callback != nullptr) {
      QObject::connect(channel_widths_callback.get(), &ULong64ValuesCallback::statusChanged,
                       this, &DeviceController::channelWidthsModelChangedSlot);
    }

    auto channel_enabled_statuses_callback = _device_cb_factory->getChannelEnabledStatusesCallback();
    if (channel_enabled_statuses_callback != nullptr) {
      QObject::connect(channel_enabled_statuses_callback.get(), &BoolValuesCallback::statusChanged,
                       this, &DeviceController::channelEnabledStatusesModelChangedSlot);
    }

    auto channel_inverted_statuses_callback = _device_cb_factory->getChannelInvertedStatusesCallback();
    if (channel_inverted_statuses_callback != nullptr) {
      QObject::connect(channel_inverted_statuses_callback.get(), &BoolValuesCallback::statusChanged,
                       this, &DeviceController::channelInvertedStatusesModelChangedSlot);
    }

    auto channel_start_sources_callback = _device_cb_factory->getChannelStartSourcesCallback();
    if (channel_start_sources_callback != nullptr) {
      QObject::connect(channel_start_sources_callback.get(), &UShortValuesCallback::statusChanged,
                       this, &DeviceController::channelStartSourcesModelChangedSlot);
    }

    auto channel_start_modes_callback = _device_cb_factory->getChannelStartModesCallback();
    if (channel_start_modes_callback != nullptr) {
      QObject::connect(channel_start_modes_callback.get(), &UShortValuesCallback::statusChanged,
                       this, &DeviceController::channelStartModesModelChangedSlot);
    }
  }

  if (_device_view != nullptr) {
    QObject::connect(_device_view.get(), &DeviceView::channelEnabledChanged,
                     this, &DeviceController::channelEnabledStatusChangedViewSlot);
    QObject::connect(_device_view.get(), &DeviceView::channelNameChanged,
                     this, &DeviceController::channelNameChangedViewSlot);
  }
//
//
//  auto positive_network_status_callback = device_cb_factory->getPositiveNetworkStatusCallback();
//  if (positive_network_status_callback != nullptr) {
//    QObject::connect(positive_network_status_callback.get(), &BoolValueCallback::statusChanged,
//                     this, &DeviceController::positiveNetworkStatusModelChanged);
//  }
//
//
//  if (_device_view != nullptr) {
//    QObject::connect(_device_view.get(), &DeviceView::CPSStatusChanged,
//                     this, &DeviceController::cpsStatusViewChanged);
//  }
}

void DeviceController::channelNameChangedViewSlot(int channel_num, const QString &value) {
  if (_use_case_factory != nullptr) {
    auto set_channel_name_use_case = _use_case_factory->createSetChannelNameUseCase();
    if (set_channel_name_use_case != nullptr) {
      SetChannelNameUseCaseRequest request{channel_num, value};
      auto response = set_channel_name_use_case->execute(request);
      // TODO: Добавить обработку ошибок

      if (response.error_code == SUCCESS) {
        if (_device_view != nullptr) {
          _device_view->setChannelName(channel_num, value);
        }
      }

    } else {
      qWarning() << "set_channel_name_use_case is not created " << __func__;
    }
  } else {
    qWarning() << "_use_case_factory is nullptr " << __func__;
  }
}

void DeviceController::channelEnabledStatusChangedViewSlot(int channel_num, bool value) {
  if (_use_case_factory != nullptr) {
    auto set_channel_enabled_status_use_case = _use_case_factory->createSetChannelEnabledStatusUseCase();
    if (set_channel_enabled_status_use_case != nullptr) {
      SetChannelEnabledStatusUseCaseRequest request{channel_num, value};
      auto response = set_channel_enabled_status_use_case->execute(request);
      // TODO: Добавить обработку ошибок

    } else {
      qWarning() << "set_channel_enabled_status_use_case is not created " << __func__;
    }
  } else {
    qWarning() << "_use_case_factory is nullptr " << __func__;
  }
}

void DeviceController::syncDesLockModelChangedSlot(bool value) {
  if (_device_view != nullptr) {
    _device_view->setSyncDesLock(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncOscLockModelChangedSlot(bool value) {
  if (_device_view != nullptr) {
    _device_view->setSyncOscLock(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncRxLossModelChangedSlot(bool value) {
  if (_device_view != nullptr) {
    _device_view->setSyncRxLoss(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncTxFaultModelChangedSlot(bool value) {
  if (_device_view != nullptr) {
    _device_view->setSyncTxFault(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncSFPTempModelChangedSlot(double value) {
  if (_device_view != nullptr) {
    _device_view->setSyncSFPTemp(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncSFPTxVoltageModelChangedSlot(double value) {
  if (_device_view != nullptr) {
    _device_view->setSyncSFPTxVoltage(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncSFPTxAmperageModelChangedSlot(double value) {
  if (_device_view != nullptr) {
    _device_view->setSyncSFPTxAmperage(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncSFPTxOpticalPowerModelChangedSlot(double value) {
  if (_device_view != nullptr) {
    _device_view->setSyncSFPTxOpticalPower(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::syncSFPRxPowerModelChangedSlot(double value) {
  if (_device_view != nullptr) {
    _device_view->setSyncSFPRxPower(value);
  } else {
    qCritical() << "device view is nullptr " << __func__;
  }
}

void DeviceController::channelNameModelChangedSlot(const QVector<QString> &value) {
  if (_device_view != nullptr) {
    for (int i = 0; i < value.size(); i++) {
      _device_view->setChannelName(i, value[i]);
    }
  }
}

void DeviceController::channelDelaysModelChangedSlot(const QVector<uint64_t> &value) {
  qDebug() << "Channel delays are " << value << " " << __func__;

  if (_device_view != nullptr) {
    for (int i = 0; i < value.count(); i++) {
      _device_view->setChannelDelay(i, value[i]);
    }
  } else {
    qCritical() << "Device view is nullptr " << __func__;
  }
}

void DeviceController::channelWidthsModelChangedSlot(const QVector<uint64_t> &value) {
  if (_device_view != nullptr) {
    for (int i = 0; i < value.count(); i++) {
      _device_view->setChannelWidth(i, value[i]);
    }
  } else {
    qCritical() << "Device view is nullptr " << __func__;
  }
}

void DeviceController::channelEnabledStatusesModelChangedSlot(const QVector<bool> &value) {
  if (_device_view != nullptr) {
    for (int i = 0; i < value.count(); i++) {
      _device_view->setChannelEnabledStatus(i, value[i]);
    }
  } else {
    qCritical() << "Device view is nullptr " << __func__;
  }
}

void DeviceController::channelInvertedStatusesModelChangedSlot(const QVector<bool> &value) {
  if (_device_view != nullptr) {
    for (int i = 0; i < value.count(); i++) {
      _device_view->setChannelInvertedStatus(i, value[i]);
    }
  } else {
    qCritical() << "Device view is nullptr " << __func__;
  }
}

void DeviceController::channelStartSourcesModelChangedSlot(const QVector<uint16_t> &value) {
  if (_device_view != nullptr) {
    for (int i = 0; i < value.count(); i++) {
      _device_view->setChannelStartSource(i, value[i]);
    }
  } else {
    qCritical() << "Device view is nullptr " << __func__;
  }
}

void DeviceController::channelStartModesModelChangedSlot(const QVector<uint16_t> &value) {
  if (_device_view != nullptr) {
    for (int i = 0; i < value.count(); i++) {
      _device_view->setChannelStartMode(i, value[i]);
    }
  } else {
    qCritical() << "Device view is nullptr " << __func__;
  }
}

void DeviceController::innerStartPeriodModelChangedSlot(quint64 value) {
    if (_device_view != nullptr) {
        _device_view->setInnerStartPeriod(value);
    }
}