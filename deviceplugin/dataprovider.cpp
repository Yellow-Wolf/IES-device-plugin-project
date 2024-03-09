#include "dataprovider.h"

#include "deviceplugin/consts.h"

static const std::string DEFAULT_DEVICE_NAME = "untitled";
static const std::string DEFAULT_DEVICE_DESCRIPTION = "";

static const std::string PLUGIN_VERSION = "1.0.0";
static const std::string DEVICE_FIRMWARE_VERSION = "unknown";


DevicePluginDataProvider::DevicePluginDataProvider(const std::shared_ptr<DeviceEntity> &test_device_entity):
    _device_entity(test_device_entity) {

}

std::string DevicePluginDataProvider::getPluginName() {
  return PLUGIN_NAME;
}

std::string DevicePluginDataProvider::getPluginDescription() {
  return PLUGIN_DESCRIPTION;
}

std::string DevicePluginDataProvider::getPluginVersion() {
  return PLUGIN_VERSION;
}

std::string DevicePluginDataProvider::getPluginDeveloperInfo() {
  return PLUGIN_DEVELOPER_INFO;
}

QIcon *DevicePluginDataProvider::getPluginIcon() {
  return nullptr;
}

std::string DevicePluginDataProvider::getDeviceName() {
  std::string result = DEFAULT_DEVICE_NAME;

  if (_device_entity != nullptr) {
    result = _device_entity->getDeviceName();
  }

  return result;
}

std::string DevicePluginDataProvider::getDeviceDescription() {
  std::string result = DEFAULT_DEVICE_DESCRIPTION;

  if (_device_entity != nullptr) {
    result = _device_entity->getDeviceDescription();
  }

  return result;
}

std::string DevicePluginDataProvider::getDeviceType() {
  return DEVICE_TYPE;
}

std::string DevicePluginDataProvider::getDeviceFirmwareVersion() {
  return DEVICE_FIRMWARE_VERSION;
}

std::string DevicePluginDataProvider::getDeviceDeveloperInfo() {
  return DEVICE_DEVELOPER_INFO;
}

DeviceState DevicePluginDataProvider::getDeviceState() {
  auto result = NOT_CONNECTED;

  if (_device_entity != nullptr) {
    result = _device_entity->getDeviceState();
  }

  return result;
}

void DevicePluginDataProvider::setDeviceName(const std::string &value) {
  if (_device_entity != nullptr) {
    _device_entity->setDeviceName(value);
  }
}

void DevicePluginDataProvider::setDeviceDescription(const std::string &value) {
  if (_device_entity != nullptr) {
    _device_entity->setDeviceDescription(value);
  }
}

