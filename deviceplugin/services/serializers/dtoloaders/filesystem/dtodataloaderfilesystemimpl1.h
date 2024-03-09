#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTOLOADERS_FILESYSTEM_DTODATALOADERFILESYSTEMIMPL1_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTOLOADERS_FILESYSTEM_DTODATALOADERFILESYSTEMIMPL1_H_

#include "deviceplugin/services/serializers/dtodataloader.h"


class DTODataLoaderFileSystemImpl1: public DTODataLoader {
 public:
  ErrorCode saveData(const std::string &data_name, const std::string &data) override;
  std::string loadData(const std::string &data_name, ErrorCode *error_code) override;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_SERVICES_SERIALIZERS_DTOLOADERS_FILESYSTEM_DTODATALOADERFILESYSTEMIMPL1_H_
