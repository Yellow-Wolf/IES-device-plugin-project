#include "channelmodel.h"

#include <QDebug>


static const QString GET_CHANNELS_COUNT_COMMAND_NAME = "getChannelsCount";
static const QString GET_CHANNEL_NAME_COMMAND_NAME = "getChannelName";
static const QString GET_CHANNEL_WIDTH_COMMAND_NAME = "getChannelWidth";
static const QString GET_CHANNEL_DELAY_COMMAND_NAME = "getChannelDelay";
static const QString GET_CHANNEL_ENABLED_STATUS_COMMAND_NAME = "getChannelEnabledStatus";
static const QString GET_CHANNEL_INVERTED_STATUS_COMMAND_NAME = "getChannelInvertedStatus";


ChannelModel::ChannelModel(const std::shared_ptr<PluginProviderStorage> &plugin_provider_storage):
    _plugin_provider_storage(plugin_provider_storage),
    _get_channels_count_command_name(GET_CHANNELS_COUNT_COMMAND_NAME),
    _get_channel_name_command_name(GET_CHANNEL_NAME_COMMAND_NAME),
    _get_channel_width_command_name(GET_CHANNEL_WIDTH_COMMAND_NAME),
    _get_channel_delay_command_name(GET_CHANNEL_DELAY_COMMAND_NAME),
    _get_channel_enabled_status_command_name(GET_CHANNEL_ENABLED_STATUS_COMMAND_NAME),
    _get_channel_inverted_status_command_name(GET_CHANNEL_INVERTED_STATUS_COMMAND_NAME) {

}

int ChannelModel::getChannelCount() {
  int result = 0;

  if (_plugin_provider_storage != nullptr) {
    auto devices = _plugin_provider_storage->getAllDevices();
    std::for_each(std::begin(devices), std::end(devices), [&](const std::pair<std::string, std::shared_ptr<PluginProvider>> &device_pair) {
      auto device = device_pair.second;
      result += getChannelCount(device);
    });
  }

  return result;
}

int ChannelModel::getColumnsCount() {
  return 2;
}

std::pair<std::shared_ptr<PluginProvider>, int> ChannelModel::getPluginProviderByChannelNum(int channel_num) {
  std::pair<std::shared_ptr<PluginProvider>, int> result = {nullptr, -1};
  auto all_devices = _plugin_provider_storage->getAllDevices();

  int current_channel_shift = 0;
  for (int i = 0; i < all_devices.size(); i++) {
    auto current_device = all_devices[i].second;
    if (current_device != nullptr) {
      auto current_device_channel_count = getChannelCount(current_device);
      if (current_device_channel_count != 0) {
        auto relative_channel_num = channel_num - current_channel_shift;
        if (relative_channel_num >= 0 && relative_channel_num < current_device_channel_count) {
          return {current_device, relative_channel_num};
        }
      }

      current_channel_shift += current_device_channel_count;
    }
  }

  return result;
}

ChannelDTO ChannelModel::getChannelData(int channel_num) {
  ChannelDTO result;

  auto all_devices = _plugin_provider_storage->getAllDevices();

  int current_channel_shift = 0;
  for (int i = 0; i < all_devices.size(); i++) {
    auto current_device = all_devices[i].second;
    if (current_device != nullptr) {
      auto current_device_channel_count = getChannelCount(current_device);
      if (current_device_channel_count != 0) {
        auto relative_channel_num = channel_num - current_channel_shift;
        if (relative_channel_num >= 0 && relative_channel_num < current_device_channel_count) {
          result = getChannelDataByRelativeNum(current_device, relative_channel_num);
          return result;
        }
      }

      current_channel_shift += current_device_channel_count;
    }
  }

  return result;
}

ChannelDTO ChannelModel::getChannelDataByRelativeNum(const std::shared_ptr<PluginProvider> &device, int channel_num) {
  ChannelDTO result;

  bool has_name_command = device->hasCommandByKey(_get_channel_name_command_name);
  if (has_name_command) {
    auto response = device->executeCommandByKey({_get_channel_name_command_name, channel_num});
    QString name = response.response.toString();

    result.channel_name = name.toStdString();
  }

  bool has_delay_command = device->hasCommandByKey(_get_channel_delay_command_name);
  if (has_delay_command) {
    auto response = device->executeCommandByKey({_get_channel_delay_command_name, channel_num});
    uint64_t delay = response.response.toULongLong();

    result.channel_delay = delay;
  }

  bool has_width_command = device->hasCommandByKey(_get_channel_width_command_name);
  if (has_width_command) {
    auto response = device->executeCommandByKey({_get_channel_width_command_name, channel_num});
    uint64_t width = response.response.toULongLong();

    result.channel_width = width;
  }

  bool has_enabled_status_command = device->hasCommandByKey(_get_channel_enabled_status_command_name);
  if (has_enabled_status_command) {
    auto response = device->executeCommandByKey({_get_channel_enabled_status_command_name, channel_num});
    bool enabled = response.response.toBool();
    result.channel_enabled = enabled;
  }

  bool has_inverted_status_command = device->hasCommandByKey(_get_channel_inverted_status_command_name);
  if (has_inverted_status_command) {
    auto response = device->executeCommandByKey({_get_channel_inverted_status_command_name, channel_num});
    bool inverted = response.response.toBool();
    result.channel_inverted = inverted;
  }

  return result;
}

bool ChannelModel::isDeviceTimer(const std::shared_ptr<PluginProvider> &device) {
  bool result = false;

  if (device != nullptr) {
    result = device->hasCommandByKey(_get_channels_count_command_name);
    if (!result) return result;

    result = device->hasCommandByKey(_get_channel_delay_command_name);
    if (!result) return result;
  }

  return result;
}

int ChannelModel::getChannelCount(const std::shared_ptr<PluginProvider> &device) {
  int result = 0;

  bool is_device_timer = isDeviceTimer(device);
  if (is_device_timer) {
    auto response = device->executeCommandByKey({_get_channels_count_command_name});

    if (response.error_code == SUCCESS) {
      result = response.response.toInt();
    } else {
      qCritical() << "Command for getting channel count returned not SUCCESS code! " << __func__;
    }
  }

  return result;
}
