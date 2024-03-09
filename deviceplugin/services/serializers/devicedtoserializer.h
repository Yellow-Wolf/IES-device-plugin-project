#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DEVICEDTOSERIALIZER_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DEVICEDTOSERIALIZER_H_

#include <memory>

#include "dtodataloader.h"
#include "dtodataparser.h"


class DeviceDTOSerializer {
 public:
  explicit DeviceDTOSerializer(const std::shared_ptr<DTODataParser> &parser,
                               const std::shared_ptr<DTODataLoader> &loader);

  std::shared_ptr<DeviceEntityDTO> deserialize(const std::string &data_name, ErrorCode *error_code = nullptr);
  ErrorCode serialize(const std::shared_ptr<DeviceEntityDTO> &dto, const std::string &data_name);

 private:
  std::shared_ptr<DTODataParser> _parser = nullptr;
  std::shared_ptr<DTODataLoader> _loader = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DEVICEDTOSERIALIZER_H_
