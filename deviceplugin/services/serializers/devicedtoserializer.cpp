#include "devicedtoserializer.h"

DeviceDTOSerializer::DeviceDTOSerializer(const std::shared_ptr<DTODataParser> &parser,
                                         const std::shared_ptr<DTODataLoader> &loader):
                                         _parser(parser),
                                         _loader(loader) {

}

std::shared_ptr<DeviceEntityDTO> DeviceDTOSerializer::deserialize(const std::string &data_name, ErrorCode *error_code) {
  std::shared_ptr<DeviceEntityDTO> result = nullptr;
  if (error_code != nullptr) *error_code = OPERATION_INTERRUPTED;

  if (_parser != nullptr && _loader != nullptr) {
    auto data = _loader->loadData(data_name, error_code);

    if (error_code != nullptr) {
      if (*error_code == SUCCESS) {
        result = _parser->parseDeviceDTO(data);
      }
    } else {
      result = _parser->parseDeviceDTO(data);
    }
  }

  return result;
}

ErrorCode DeviceDTOSerializer::serialize(const std::shared_ptr<DeviceEntityDTO> &dto, const std::string &data_name) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_parser != nullptr && _loader != nullptr) {
    auto data = _parser->encodeDeviceDTO(dto);
    result = _loader->saveData(data, data_name);
  }

  return result;
}

