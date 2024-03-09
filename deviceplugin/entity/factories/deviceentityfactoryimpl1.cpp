#include "deviceentityfactoryimpl1.h"
#include "deviceplugin/entity/impls/deviceentityimpl.h"


DeviceEntityFactoryImpl1::DeviceEntityFactoryImpl1(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory):
 _modbus_wrapper_factory(modbus_wrapper_factory) {

}

std::shared_ptr<DeviceEntity> DeviceEntityFactoryImpl1::createDeviceEntity(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                                           const std::shared_ptr<DeviceEntityDTO> &dto) {
  // TODO: Здесь определить создание девайса

  std::shared_ptr<DeviceEntity> result = nullptr;
//  result = std::make_shared<DeviceEntityImpl>();
  return result;
}
