#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_FACTORIES_TESTDEVICEENTITYFACTORYIMPL1_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_FACTORIES_TESTDEVICEENTITYFACTORYIMPL1_H_

#include <memory>

#include <modbuswrappers/modbuswrapperfactory.h>

#include "deviceplugin/entity/deviceentityfactory.h"


class DeviceEntityFactoryImpl1: public DeviceEntityFactory {
 public:
  explicit DeviceEntityFactoryImpl1(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory);

  std::shared_ptr<DeviceEntity> createDeviceEntity(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                   const std::shared_ptr<DeviceEntityDTO> &dto) override;

 private:
  std::shared_ptr<ModbusWrapperFactory> _modbus_wrapper_factory = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_FACTORIES_TESTDEVICEENTITYFACTORYIMPL1_H_
