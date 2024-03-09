#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTODATAPARSER_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTODATAPARSER_H_

#include <memory>

#include <deviceplugin/entity/devicetypes.h>


class DTODataParser {
 public:
  virtual std::shared_ptr<DeviceEntityDTO> parseDeviceDTO(const std::string &data) = 0;
  virtual std::string encodeDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) = 0;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTODATAPARSER_H_
