#include "channeleditcontroller.h"

#include <QDebug>


ChannelEditController::ChannelEditController(const std::shared_ptr<DeviceCallbackSubscriptionFactory> &device_cb_factory,
                                             const std::shared_ptr<ChannelEditDialog> &channel_edit_view,
                                             const std::shared_ptr<GetChannelDelayUseCase> &get_channel_delay_use_case,
                                             const std::shared_ptr<SetChannelEnabledStatusUseCase> &set_channel_enabled_status_use_case,
                                             QObject *parent):
                                             _device_cb_factory(device_cb_factory),
                                             _channel_edit_view(channel_edit_view),
                                             _get_channel_delay_use_case(get_channel_delay_use_case),
                                             _set_channel_enabled_status_use_case(set_channel_enabled_status_use_case),
                                             QObject(parent) {
  setConnections();
}

void ChannelEditController::setCurrentChannel(int current_channel) {
  _current_channel = current_channel;
  if (_channel_edit_view != nullptr) {
    _channel_edit_view->setChannelNum(_current_channel);
  }
}

std::shared_ptr<QWidget> ChannelEditController::getView() {
  return _channel_edit_view;
}

void ChannelEditController::setConnections() {
  if (_channel_edit_view != nullptr) {
//    QObject::connect(_channel_edit_view.get(), &ChannelEditDialog::channelDelayChanged,
//                     this, &ChannelEditController::channelDelayChangedViewSlot);

    QObject::connect(_channel_edit_view.get(), &ChannelEditDialog::channelEnabledChanged,
                     this, &ChannelEditController::channelEnabledStatusChangedViewSlot);
  }
  
  if (_device_cb_factory != nullptr) {
    auto channel_names_callback = _device_cb_factory->getChannelNameCallback();
    if (channel_names_callback != nullptr) {
      QObject::connect(channel_names_callback.get(), &StringValuesCallback::statusChanged,
                       this, &ChannelEditController::channelNameModelChangedSlot);
      qDebug() << "CHANNEL Names CONNECTED";
    }

    auto channel_delays_callback = _device_cb_factory->getChannelDelaysCallback();
    if (channel_delays_callback != nullptr) {
      QObject::connect(channel_delays_callback.get(), &ULong64ValuesCallback::statusChanged,
                       this, &ChannelEditController::channelDelaysChangedModelSlot);
      qDebug() << "CHANNEL DELAYS CONNECTED";
    }

    auto channel_widths_callback = _device_cb_factory->getChannelWidthsCallback();
    if (channel_widths_callback != nullptr) {
      QObject::connect(channel_widths_callback.get(), &ULong64ValuesCallback::statusChanged,
                       this, &ChannelEditController::channelWidthsChangedModelSlot);
    }

    auto channel_enabled_statuses_callback = _device_cb_factory->getChannelEnabledStatusesCallback();
    if (channel_enabled_statuses_callback != nullptr) {
      QObject::connect(channel_enabled_statuses_callback.get(), &BoolValuesCallback::statusChanged,
                       this, &ChannelEditController::channelEnabledStatusesChangedModelSlot);
    }

    auto channel_inverted_statuses_callback = _device_cb_factory->getChannelInvertedStatusesCallback();
    if (channel_inverted_statuses_callback != nullptr) {
      QObject::connect(channel_inverted_statuses_callback.get(), &BoolValuesCallback::statusChanged,
                       this, &ChannelEditController::channelInvertedStatusesChangedModelSlot);
    }

    auto channel_start_sources_callback = _device_cb_factory->getChannelStartSourcesCallback();
    if (channel_start_sources_callback != nullptr) {
      QObject::connect(channel_start_sources_callback.get(), &UShortValuesCallback::statusChanged,
                       this, &ChannelEditController::channelStartSourceChangedModelSlot);
    }

    auto channel_start_modes_callback = _device_cb_factory->getChannelStartModesCallback();
    if (channel_start_modes_callback != nullptr) {
      QObject::connect(channel_start_modes_callback.get(), &UShortValuesCallback::statusChanged,
                       this, &ChannelEditController::channelStartModesChangedModelSlot);
    }
  }
}

void ChannelEditController::channelNameModelChangedSlot(const QVector<QString> &values) {
  if (_channel_edit_view != nullptr) {
    for (int i = 0; i < values.size(); i++) {
      _channel_edit_view->setChannelName(i, values[i]);
    }
  }
}

void ChannelEditController::channelDelaysChangedModelSlot(const QVector<uint64_t> &values) {
  if (_channel_edit_view != nullptr) {
    for (int i = 0; i < values.size(); i++) {
      _channel_edit_view->setChannelDelay(i, values[i]);
    }
  }
}

void ChannelEditController::channelWidthsChangedModelSlot(const QVector<uint64_t> &values) {
  if (_channel_edit_view != nullptr) {
    for (int i = 0; i < values.size(); i++) {
      _channel_edit_view->setChannelWidth(i, values[i]);
    }
  }
}

void ChannelEditController::channelEnabledStatusesChangedModelSlot(const QVector<bool> &values) {
  if (_channel_edit_view != nullptr) {
    for (int i = 0; i < values.size(); i++) {
      _channel_edit_view->setChannelEnabled(i, values[i]);
    }
  }
}

void ChannelEditController::channelInvertedStatusesChangedModelSlot(const QVector<bool> &values) {
  if (_channel_edit_view != nullptr) {
    for (int i = 0; i < values.size(); i++) {
      _channel_edit_view->setChannelInverted(i, values[i]);
    }
  }
}

void ChannelEditController::channelStartSourceChangedModelSlot(const QVector<uint16_t> &values) {
  if (_channel_edit_view != nullptr) {
    for (int i = 0; i < values.size(); i++) {
      _channel_edit_view->setChannelStartSource(i, values[i]);
    }
  }
}

void ChannelEditController::channelStartModesChangedModelSlot(const QVector<uint16_t> &values) {
  if (_channel_edit_view != nullptr) {
    for (int i = 0; i < values.size(); i++) {
      _channel_edit_view->setChannelStartMode(i, (ChannelMode) values[i]);
    }
  }
}

void ChannelEditController::channelNameChangedViewSlot(int channel_num, const QString &value) {
  if (_channel_edit_view != nullptr) {
    _channel_edit_view->setChannelName(channel_num, value);
  }
}

void ChannelEditController::channelDelayChangedViewSlot(int channel_num, uint64_t value) {
  if (_get_channel_delay_use_case != nullptr) {
    GetChannelDelayUseCaseRequest request;
    request.channel_num = _current_channel;

    auto response = _get_channel_delay_use_case->execute(request);

    auto result_value = response.value;
    if (_channel_edit_view != nullptr) {
      _channel_edit_view->setChannelDelay(_current_channel, result_value);
    }

    qDebug() << "IN Controller " << response.value << " " << __func__;
  }
}

void ChannelEditController::channelEnabledStatusChangedViewSlot(int channel_num, bool value) {
  if (_set_channel_enabled_status_use_case != nullptr) {
    SetChannelEnabledStatusUseCaseRequest request{channel_num, value};
    auto response = _set_channel_enabled_status_use_case->execute(request);

    // TODO: Сделать обработку ошибок
  }
}
