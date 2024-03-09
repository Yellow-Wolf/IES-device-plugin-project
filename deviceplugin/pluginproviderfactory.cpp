#include "pluginproviderfactory.h"
#include "dataprovider.h"
#include "connectionmanager.h"

static const int HOLDING_REGS_COUNT = 83;
static const int INPUT_REGS_COUNT = 15;


DevicePluginProviderFactory::DevicePluginProviderFactory(const std::shared_ptr<QWidget> &view,
                                                         const std::shared_ptr<PluginProviderStorage> &device_plugin_storage,
                                                         const std::shared_ptr<ThreadPoolBuilder> &thread_pool_builder,
                                                         const std::shared_ptr<DTODataParser> &dto_data_parser,
                                                         const std::shared_ptr<FactoryUseCase> &factory_use_case):
                                                         PluginProviderFactory(view, device_plugin_storage, thread_pool_builder),
                                                         _dto_data_parser(dto_data_parser),
                                                         _factory_use_case(factory_use_case) {

}

PluginProviderResponse DevicePluginProviderFactory::createPluginProvider(PluginProviderRequest request) {
  PluginProviderResponse response{};

  auto name = request.name;
  auto description = request.description;
  auto data = request.data;

  if (_factory_use_case != nullptr && _dto_data_parser != nullptr) {
    auto device_dto = _dto_data_parser->parseDeviceDTO(data);
    if (device_dto != nullptr) {

      auto ip = device_dto->ip;
      auto port = device_dto->port;
      auto modbus_id = device_dto->modbus_id;
      auto poll_period = device_dto->poll_period;

      FactoryUseCaseRequest factory_request{name, description, ip, port, modbus_id, poll_period};
      auto factory_response = _factory_use_case->execute(factory_request);

      auto plugin_provider = factory_response.plugin_provider;
      if (plugin_provider != nullptr) {
        plugin_provider->deserialize(data);
      }

      response.plugin_provider = plugin_provider;
    }
  }

  return response;
}

ErrorCode DevicePluginProviderFactory::destroyPluginProvider(const std::string &uid) {
  return PluginProviderFactory::destroyPluginProvider(uid);
}
