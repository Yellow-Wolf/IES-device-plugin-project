#include "serializer.h"


DevicePluginSerializer::DevicePluginSerializer(const std::shared_ptr<DeviceEntity> &test_device_entity,
                                               const std::shared_ptr<DTODataParser> &dto_parser):
    _device_entity(test_device_entity),
    _dto_parser(dto_parser) {

}

std::string DevicePluginSerializer::serialize() {
  std::string result;

  if (_dto_parser != nullptr && _device_entity != nullptr) {
    auto dto = _device_entity->getDeviceDTO();
    if (dto != nullptr) {
      result = _dto_parser->encodeDeviceDTO(dto);
    }
  }

  return result;
}

ErrorCode DevicePluginSerializer::deserialize(const std::string &data) {

  // TODO: Убрать хардкод путей. Сейчас это сделано исключительно для быстрой проверки
  if (_dto_parser != nullptr) {
    auto dto = _dto_parser->parseDeviceDTO(data);
    if (_device_entity != nullptr) {
      _device_entity->loadDeviceDTO(dto);
    }
  }

  return DEVICE_NOT_RESPONDING_LAN;
}
