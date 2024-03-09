#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTODATALOADER_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTODATALOADER_H_

#include <string>

#include <utils/baseutils.h>


class DTODataLoader {
 public:
  virtual ErrorCode saveData(const std::string &data_name, const std::string &data) = 0;
  virtual std::string loadData(const std::string &data_name, ErrorCode *error_code = nullptr) = 0;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTODATALOADER_H_
