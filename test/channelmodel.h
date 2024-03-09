#ifndef OU6UDEVICESTANDALONEPLUGIN_TEST_CHANNELMODEL_H_
#define OU6UDEVICESTANDALONEPLUGIN_TEST_CHANNELMODEL_H_

#include <plugin/storages/pluginproviderstorage.h>
#include "deviceplugin/entity/devicetypes.h"


class ChannelModel {
 public:
  explicit ChannelModel(const std::shared_ptr<PluginProviderStorage> &plugin_provider_storage);

  int getChannelCount();
  int getColumnsCount();

  ChannelDTO getChannelData(int channel_num);

  std::pair<std::shared_ptr<PluginProvider>, int> getPluginProviderByChannelNum(int channel_num);

 private:
  std::shared_ptr<PluginProviderStorage> _plugin_provider_storage = nullptr;

  const QString _get_channels_count_command_name;
  const QString _get_channel_name_command_name;
  const QString _get_channel_width_command_name;
  const QString _get_channel_delay_command_name;
  const QString _get_channel_enabled_status_command_name;
  const QString _get_channel_inverted_status_command_name;

  bool isDeviceTimer(const std::shared_ptr<PluginProvider> &device);
  int getChannelCount(const std::shared_ptr<PluginProvider> &device);

  ChannelDTO getChannelDataByRelativeNum(const std::shared_ptr<PluginProvider> &device, int channel_num);
};


#endif //OU6UDEVICESTANDALONEPLUGIN_TEST_CHANNELMODEL_H_
