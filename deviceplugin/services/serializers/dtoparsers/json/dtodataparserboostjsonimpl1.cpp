#include "dtodataparserboostjsonimpl1.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;

static const std::string DEFAULT_IP_KEY = "ip";
static const std::string DEFAULT_PORT_KEY = "port";
static const std::string DEFAULT_MODBUS_ID_KEY = "modbus_id";
static const std::string DEFAULT_POLL_PERIOD_KEY = "poll_period";

static const std::string DEFAULT_INNER_START_PERIOD_KEY = "inner_start_period";
static const std::string DEFAULT_INNER_START_WIDTH_KEY = "inner_start_width";
static const std::string DEFAULT_INNER_START_ENABLED_STATUS_KEY = "inner_start_enabled_status";
static const std::string DEFAULT_INNER_START_INVERTED_STATUS_KEY = "inner_start_inverted_status";
static const std::string DEFAULT_CHANNEL_GROUP_KEY = "channels";
static const std::string DEFAULT_CHANNEL_NAME_KEY = "channel_name";
static const std::string DEFAULT_CHANNEL_DELAY_KEY = "channel_delay";
static const std::string DEFAULT_CHANNEL_WIDTH_KEY = "channel_width";
static const std::string DEFAULT_CHANNEL_ENABLED_STATUS_KEY = "channel_enabled";
static const std::string DEFAULT_CHANNEL_INVERTED_STATUS_KEY = "channel_inverted";
static const std::string DEFAULT_CHANNEL_START_SOURCE_KEY = "channel_start_source";
static const std::string DEFAULT_CHANNEL_START_MODE_KEY = "channel_start_mode";

DTODataParserBoostJSONImpl1::DTODataParserBoostJSONImpl1():
  _ip_key(DEFAULT_IP_KEY),
  _port_key(DEFAULT_PORT_KEY),
  _modbus_id_key(DEFAULT_MODBUS_ID_KEY),
  _poll_period_key(DEFAULT_POLL_PERIOD_KEY),
  _inner_start_period_key(DEFAULT_INNER_START_PERIOD_KEY),
  _inner_start_width_key(DEFAULT_INNER_START_WIDTH_KEY),
  _inner_start_enabled_status_key(DEFAULT_INNER_START_ENABLED_STATUS_KEY),
  _inner_start_inverted_status_key(DEFAULT_INNER_START_INVERTED_STATUS_KEY),
  _channel_group_key(DEFAULT_CHANNEL_GROUP_KEY),
  _channel_name_key(DEFAULT_CHANNEL_NAME_KEY),
  _channel_delay_key(DEFAULT_CHANNEL_DELAY_KEY),
  _channel_width_key(DEFAULT_CHANNEL_WIDTH_KEY),
  _channel_enabled_status_key(DEFAULT_CHANNEL_ENABLED_STATUS_KEY),
  _channel_inverted_status_key(DEFAULT_CHANNEL_INVERTED_STATUS_KEY),
  _channel_start_source_key(DEFAULT_CHANNEL_START_SOURCE_KEY),
  _channel_start_mode_key(DEFAULT_CHANNEL_START_MODE_KEY) {

}

std::shared_ptr<DeviceEntityDTO> DTODataParserBoostJSONImpl1::parseDeviceDTO(const std::string &data) {
  std::shared_ptr<DeviceEntityDTO> result = nullptr;

  std::stringstream ss;
  ss << data;

  boost::property_tree::ptree pt;

  try {
    boost::property_tree::read_json(ss, pt);
  } catch (...) {
    return result;
  }

  try {
    result = std::make_shared<DeviceEntityDTO>();

    result->ip = pt.get<std::string>(_ip_key);
    result->port = pt.get<int>(_port_key);
    result->modbus_id = pt.get<int>(_modbus_id_key);
    result->poll_period = pt.get<int>(_poll_period_key);

    result->inner_start_period = pt.get<uint64_t>(_inner_start_period_key);
    result->inner_start_width = pt.get<uint64_t>(_inner_start_width_key);
    result->inner_start_enabled = pt.get<bool>(_inner_start_enabled_status_key);
    result->inner_start_inverted = pt.get<bool>(_inner_start_inverted_status_key);

    auto channels_node = pt.get_child(_channel_group_key);

    auto channels_count = channels_node.size();
    if (channels_count != CHANNEL_COUNT) {
      result = nullptr;
      return result;
    }

    result->channels.clear();
    for (auto &channel_data: channels_node) {
      ChannelDTO channel_dto;
      channel_dto.channel_name = channel_data.second.get<std::string>(_channel_name_key);
      channel_dto.channel_delay = channel_data.second.get<uint64_t>(_channel_delay_key);
      channel_dto.channel_width = channel_data.second.get<uint64_t>(_channel_width_key);
      channel_dto.channel_enabled = channel_data.second.get<bool>(_channel_enabled_status_key);
      channel_dto.channel_inverted = channel_data.second.get<bool>(_channel_inverted_status_key);
      channel_dto.channel_start_source = channel_data.second.get<int>(_channel_start_source_key);
      channel_dto.channel_mode = static_cast<ChannelMode>(channel_data.second.get<int>(_channel_start_mode_key));

      result->channels.push_back(channel_dto);
    }

  } catch (...) {
    result = nullptr;
    return result;
  }

  return result;
}

std::string DTODataParserBoostJSONImpl1::encodeDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  std::string result;

  if (dto != nullptr) {
    boost::property_tree::ptree pt;

    pt.put(_ip_key, dto->ip);
    pt.put(_port_key, dto->port);
    pt.put(_modbus_id_key, dto->modbus_id);
    pt.put(_poll_period_key, dto->poll_period);

    pt.put(_inner_start_period_key, dto->inner_start_period);
    pt.put(_inner_start_width_key, dto->inner_start_width);
    pt.put(_inner_start_enabled_status_key, dto->inner_start_enabled);
    pt.put(_inner_start_inverted_status_key, dto->inner_start_inverted);


    boost::property_tree::ptree channels_node;

    auto &channels_data = dto->channels;
    for (const auto &channel: channels_data) {
      boost::property_tree::ptree channel_node;
      channel_node.put(_channel_name_key, channel.channel_name);
      channel_node.put(_channel_delay_key, channel.channel_delay);
      channel_node.put(_channel_width_key, channel.channel_width);
      channel_node.put(_channel_enabled_status_key, channel.channel_enabled);
      channel_node.put(_channel_inverted_status_key, channel.channel_inverted);
      channel_node.put(_channel_start_source_key, channel.channel_start_source);
      channel_node.put(_channel_start_mode_key, channel.channel_mode);

      channels_node.push_back({"", channel_node});
    }

    pt.add_child(_channel_group_key, channels_node);

    std::ostringstream ss;
    boost::property_tree::write_json(ss, pt);

    result = ss.str();
  }

  return result;
}
