#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_SERIALIZER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_SERIALIZER_H_

#include <plugin/deviceplugins/serializer.h>

#include "deviceplugin/entity/deviceentity.h"
#include "deviceplugin/services/serializers/dtodataparser.h"

class DevicePluginSerializer: public PluginSerializer {
 public:
  explicit DevicePluginSerializer(const std::shared_ptr<DeviceEntity> &test_device_entity,
                                  const std::shared_ptr<DTODataParser> &dto_parser);

  std::string serialize() override;
  ErrorCode deserialize(const std::string &data) override;

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<DTODataParser> _dto_parser = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_SERIALIZER_H_
