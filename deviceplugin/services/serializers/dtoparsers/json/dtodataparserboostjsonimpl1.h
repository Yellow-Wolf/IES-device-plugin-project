#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTOPARSERS_JSON_DTODATAPARSERBOOSTJSONIMPL1_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTOPARSERS_JSON_DTODATAPARSERBOOSTJSONIMPL1_H_

#include "deviceplugin/services/serializers/dtodataparser.h"


class DTODataParserBoostJSONImpl1: public DTODataParser {
 public:
  explicit DTODataParserBoostJSONImpl1();

  std::shared_ptr<DeviceEntityDTO> parseDeviceDTO(const std::string &data) override;
  std::string encodeDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) override;

 private:
  const std::string _ip_key;
  const std::string _port_key;
  const std::string _modbus_id_key;
  const std::string _poll_period_key;

  const std::string _inner_start_period_key;
  const std::string _inner_start_width_key;
  const std::string _inner_start_enabled_status_key;
  const std::string _inner_start_inverted_status_key;

  const std::string _channel_group_key;
  const std::string _channel_name_key;
  const std::string _channel_delay_key;
  const std::string _channel_width_key;
  const std::string _channel_enabled_status_key;
  const std::string _channel_inverted_status_key;
  const std::string _channel_start_source_key;
  const std::string _channel_start_mode_key;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTOPARSERS_JSON_DTODATAPARSERBOOSTJSONIMPL1_H_
