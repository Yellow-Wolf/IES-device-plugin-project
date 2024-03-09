#include "deviceentitypoll.h"

#include <iostream>
#include <QVector>

#include <QDebug>



DeviceEntityPoll::DeviceEntityPoll(const std::shared_ptr<DeviceEntity> &device_entity,
                                   const std::shared_ptr<DeviceCallbackSubscriptionFactory> &callback_sub_factory,
                                   QObject *parent):
    IDeviceEntityPoll(parent),
    _device_entity(device_entity),
    _callback_sub_factory(callback_sub_factory) {

}

void DeviceEntityPoll::process() {
  qDebug() << "TASK";
  if (_device_entity == nullptr) {
    return;
  }

  if (_callback_sub_factory == nullptr) {
    return;
  }

  qDebug() << "Before entity process";
  _device_entity->process();

  qDebug() << "Before sync module statuses poll";
  SyncModuleStatusesPoll();
  SyncSFPStatusesPoll();

  channelDelaysPoll();
  channelWidthsPoll();
  channelEnabledStatusesPoll();
  channelInvertedStatusesPoll();
  channelStartModesPoll();
  channelStartSourcesPoll();
}

void DeviceEntityPoll::SyncModuleStatusesPoll() {
  auto des_lock_callback = _callback_sub_factory->getSyncDesLockCallback();
  auto osc_lock_callback = _callback_sub_factory->getSyncOscLockCallback();
  auto rx_loss_callback = _callback_sub_factory->getSyncRxLossCallback();
  auto tx_fault_callback = _callback_sub_factory->getSyncTxFaultCallback();

  if (des_lock_callback != nullptr && osc_lock_callback != nullptr &&
      rx_loss_callback != nullptr && tx_fault_callback != nullptr && _device_entity != nullptr) {
    auto response = _device_entity->getSyncModuleStatuses({});
    auto error_code = response.error_code;
    if (error_code == SUCCESS) {
      bool des_lock = response.des_lock;
      bool osc_lock = response.osc_lock;
      bool rx_loss = response.rx_loss;
      bool tx_fault = response.tx_fault;

      des_lock_callback->pushEvent(des_lock);
      osc_lock_callback->pushEvent(osc_lock);
      rx_loss_callback->pushEvent(rx_loss);
      tx_fault_callback->pushEvent(tx_fault);

      std::cout << "VALUE " << des_lock << " " << osc_lock << " " << rx_loss << " " << tx_fault << " " << __func__ << std::endl;
    } else {
      std::cerr << "ERROR WHILE " << __func__ << std::endl;
    }
  }
}


void DeviceEntityPoll::SyncSFPStatusesPoll() {
  auto temp_callback = _callback_sub_factory->getSyncSFPTempCallback();
  auto tx_voltage_callback = _callback_sub_factory->getSyncSFPTxVoltageCallback();
  auto tx_amperage_callback = _callback_sub_factory->getSyncSFPTxAmperageCallback();
  auto tx_optical_power_callback = _callback_sub_factory->getSyncSFPTxOpticalPowerCallback();
  auto rx_power_callback = _callback_sub_factory->getSyncSFPRxPowerCallback();

  if (temp_callback != nullptr && tx_voltage_callback != nullptr && tx_amperage_callback != nullptr
      && tx_optical_power_callback != nullptr && rx_power_callback != nullptr && _device_entity != nullptr) {
    auto response = _device_entity->getSFPParameters({});
    auto error_code = response.error_code;
    if (error_code == SUCCESS) {
      auto &sfp_params = response.result;
      double temp = sfp_params.temperature;
      double tx_voltage = sfp_params.voltage;
      double tx_amperage = sfp_params.tx_amperage_shift;
      double tx_optical_power = sfp_params.tx_optical_power;
      double rx_power = sfp_params.rx_power;

      temp_callback->pushEvent(temp);
      tx_voltage_callback->pushEvent(tx_voltage);
      tx_amperage_callback->pushEvent(tx_amperage);
      tx_optical_power_callback->pushEvent(tx_optical_power);
      rx_power_callback->pushEvent(rx_power);

    } else {
      std::cerr << "ERROR WHILE " << __func__ << std::endl;
    }
  }
}

void DeviceEntityPoll::channelDelaysPoll() {
  auto callback = _callback_sub_factory->getChannelDelaysCallback();
  if (callback != nullptr && _device_entity != nullptr) {
    int channel_count = _device_entity->getChannelCount();


    QVector<uint64_t> delay_values;

    for (int i = 0; i < channel_count; i++) {
      GetChannelDelayRequest entity_request{i};
      auto entity_response = _device_entity->getChannelsDelay(entity_request);

      // TODO: Добавить здесь перехват ошибки
      uint64_t value = entity_response.result;
      delay_values.push_back(value);
    }

    callback->pushEvent(delay_values);
    qDebug() << "CALLBACK CHANNEL DELAY PUSHED " << __func__;
  }
}

void DeviceEntityPoll::channelWidthsPoll() {
  auto callback = _callback_sub_factory->getChannelWidthsCallback();
  if (callback != nullptr && _device_entity != nullptr) {
    int channel_count = _device_entity->getChannelCount();


    QVector<uint64_t> values;

    for (int i = 0; i < channel_count; i++) {
      GetChannelWidthRequest entity_request{i};
      auto entity_response = _device_entity->getChannelsWidth(entity_request);

      // TODO: Добавить здесь перехват ошибки
      uint64_t value = entity_response.result;
      values.push_back(value);
    }

    callback->pushEvent(values);
    qDebug() << "CALLBACK CHANNEL DELAY PUSHED " << __func__;
  }
}

void DeviceEntityPoll::channelStartSourcesPoll() {
  auto callback = _callback_sub_factory->getChannelStartSourcesCallback();
  if (callback != nullptr && _device_entity != nullptr) {
    int channel_count = _device_entity->getChannelCount();


    QVector<uint16_t> values;

    for (int i = 0; i < channel_count; i++) {
      GetChannelStartSourceRequest entity_request{i};
      auto entity_response = _device_entity->getChannelsStartSource(entity_request);

      // TODO: Добавить здесь перехват ошибки
      int16_t value = entity_response.result;
      values.push_back(value);
    }

    callback->pushEvent(values);
    qDebug() << "CALLBACK CHANNEL DELAY PUSHED " << __func__;
  }
}

void DeviceEntityPoll::channelStartModesPoll() {
  auto callback = _callback_sub_factory->getChannelStartModesCallback();
  if (callback != nullptr && _device_entity != nullptr) {
    int channel_count = _device_entity->getChannelCount();


    QVector<uint16_t> values;

    for (int i = 0; i < channel_count; i++) {
      GetChannelStartModeRequest entity_request{i};
      auto entity_response = _device_entity->getChannelsStartMode(entity_request);

      // TODO: Добавить здесь перехват ошибки
      auto value = static_cast<ChannelMode>(entity_response.result);
      values.push_back(value);
    }

    callback->pushEvent(values);
    qDebug() << "CALLBACK CHANNEL DELAY PUSHED " << __func__;
  }
}

void DeviceEntityPoll::channelEnabledStatusesPoll() {
  auto callback = _callback_sub_factory->getChannelEnabledStatusesCallback();
  if (callback != nullptr && _device_entity != nullptr) {
    int channel_count = _device_entity->getChannelCount();


    QVector<bool> values;

    for (int i = 0; i < channel_count; i++) {
      GetChannelEnabledStatusRequest entity_request{i};
      auto entity_response = _device_entity->getChannelsEnabledStatus(entity_request);

      // TODO: Добавить здесь перехват ошибки
      bool value = entity_response.result;
      values.push_back(value);
    }

    callback->pushEvent(values);
    qDebug() << "CALLBACK CHANNEL DELAY PUSHED " << __func__;
  }
}

void DeviceEntityPoll::channelInvertedStatusesPoll() {
  auto callback = _callback_sub_factory->getChannelInvertedStatusesCallback();
  if (callback != nullptr && _device_entity != nullptr) {
    int channel_count = _device_entity->getChannelCount();


    QVector<bool> values;

    for (int i = 0; i < channel_count; i++) {
      GetChannelInvertedStatusRequest entity_request{i};
      auto entity_response = _device_entity->getChannelsInvertedStatus(entity_request);

      // TODO: Добавить здесь перехват ошибки
      bool value = entity_response.result;
      values.push_back(value);
    }

    callback->pushEvent(values);
    qDebug() << "CALLBACK CHANNEL DELAY PUSHED " << __func__;
  }
}

void DeviceEntityPoll::channelNamesPoll() {
  auto callback = _callback_sub_factory->getChannelNameCallback();
  if (callback != nullptr && _device_entity != nullptr) {
    int channel_count = _device_entity->getChannelCount();

    QVector<QString> values;

    for (int i = 0; i < channel_count; i++) {
      GetChannelNameRequest entity_request{i};
      auto entity_response = _device_entity->getChannelName(entity_request);

      // TODO: Добавить здесь перехват ошибки
      auto value = entity_response.result;
      values.push_back(QString::fromStdString(value));
    }

    callback->pushEvent(values);
    qDebug() << "CALLBACK CHANNEL DELAY PUSHED " << __func__;
  }
}
