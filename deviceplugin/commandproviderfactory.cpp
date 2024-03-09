#include <plugin/deviceplugins/commandproviders/commandproviderimpl1.h>
#include "commandproviderfactory.h"

#include <QDebug>


static const QString GET_CHANNELS_COUNT_COMMAND_NAME = "getChannelsCount";

static const QString GET_CHANNEL_NAME_COMMAND_NAME = "getChannelName";
static const QString GET_CHANNEL_DELAY_COMMAND_NAME = "getChannelDelay";
static const QString GET_CHANNEL_WIDTH_COMMAND_NAME = "getChannelWidth";
static const QString GET_CHANNEL_ENABLED_STATUS_COMMAND_NAME = "getChannelEnabledStatus";
static const QString GET_CHANNEL_INVERTED_STATUS_COMMAND_NAME = "getChannelInvertedStatus";
static const QString GET_CHANNEL_START_SOURCE_COMMAND_NAME = "getChannelStartSource";
static const QString GET_CHANNEL_START_MODE_COMMAND_NAME = "getChannelStartMode";

static const QString SET_CHANNELS_COUNT_COMMAND_NAME = "setChannelsCount";
static const QString SET_CHANNEL_DELAY_COMMAND_NAME = "setChannelDelay";
static const QString SET_CHANNEL_WIDTH_COMMAND_NAME = "setChannelWidth";
static const QString SET_CHANNEL_ENABLED_STATUS_COMMAND_NAME = "setChannelEnabledStatus";
static const QString SET_CHANNEL_INVERTED_STATUS_COMMAND_NAME = "setChannelInvertedStatus";
static const QString SET_CHANNEL_START_SOURCE_COMMAND_NAME = "setChannelStartSource";
static const QString SET_CHANNEL_START_MODE_COMMAND_NAME = "setChannelStartMode";


std::shared_ptr<PluginCommandProvider> CommandProviderFactory::createCommandProvider(const std::shared_ptr<
    UseCaseFactory> &use_case_factory) {
  std::shared_ptr<PluginCommandProvider> command_provider = nullptr;

  if (use_case_factory != nullptr) {
    command_provider = std::make_shared<CommandProviderImpl1>();

    auto get_channels_count_use_case = use_case_factory->createGetChannelsCountUseCase();
    if (get_channels_count_use_case != nullptr) {
      auto command = std::make_shared<GetChannelsCountCommand>(get_channels_count_use_case);
      command_provider->addCommand(GET_CHANNELS_COUNT_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channels_count_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto get_channels_name_use_case = use_case_factory->createGetChannelNameUseCase();
    if (get_channels_name_use_case != nullptr) {
      auto command = std::make_shared<GetChannelNameCommand>(get_channels_name_use_case);
      command_provider->addCommand(GET_CHANNEL_NAME_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channels_name_use_case is nullptr and cannot be added to command provider " << __func__;
    }


    auto get_channel_delay_use_case = use_case_factory->createGetChannelDelayUseCase();
    if (get_channel_delay_use_case != nullptr) {
      auto command = std::make_shared<GetChannelDelayCommand>(get_channel_delay_use_case);
      command_provider->addCommand(GET_CHANNEL_DELAY_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channel_delay_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto get_channel_width_use_case = use_case_factory->createGetChannelWidthUseCase();
    if (get_channel_width_use_case != nullptr) {
      auto command = std::make_shared<GetChannelWidthCommand>(get_channel_width_use_case);
      command_provider->addCommand(GET_CHANNEL_WIDTH_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channel_width_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto get_channel_enabled_status_use_case = use_case_factory->createGetChannelEnabledStatusUseCase();
    if (get_channel_enabled_status_use_case != nullptr) {
      auto command = std::make_shared<GetChannelEnabledStatusCommand>(get_channel_enabled_status_use_case);
      command_provider->addCommand(GET_CHANNEL_ENABLED_STATUS_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channel_enabled_status_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto get_channel_inverted_status_use_case = use_case_factory->createGetChannelInvertedStatusUseCase();
    if (get_channel_inverted_status_use_case != nullptr) {
      auto command = std::make_shared<GetChannelInvertedStatusCommand>(get_channel_inverted_status_use_case);
      command_provider->addCommand(GET_CHANNEL_INVERTED_STATUS_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channel_inverted_status_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto get_channel_start_source_use_case = use_case_factory->createGetChannelStartSourceUseCase();
    if (get_channel_start_source_use_case != nullptr) {
      auto command = std::make_shared<GetChannelStartSourceCommand>(get_channel_start_source_use_case);
      command_provider->addCommand(GET_CHANNEL_START_SOURCE_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channel_start_source_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto get_channel_start_mode_use_case = use_case_factory->createGetChannelStartModeUseCase();
    if (get_channel_start_mode_use_case != nullptr) {
      auto command = std::make_shared<GetChannelStartModeCommand>(get_channel_start_mode_use_case);
      command_provider->addCommand(GET_CHANNEL_START_MODE_COMMAND_NAME, command);
    } else {
      qWarning() << "get_channel_start_mode_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto set_channel_delay_use_case = use_case_factory->createSetChannelDelayUseCase();
    if (set_channel_delay_use_case != nullptr) {
      auto command = std::make_shared<SetChannelDelayCommand>(set_channel_delay_use_case);
      command_provider->addCommand(SET_CHANNEL_DELAY_COMMAND_NAME, command);
    } else {
      qWarning() << "set_inner_start_period_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto set_channel_width_use_case = use_case_factory->createSetChannelWidthUseCase();
    if (set_channel_width_use_case != nullptr) {
      auto command = std::make_shared<SetChannelWidthCommand>(set_channel_width_use_case);
      command_provider->addCommand(SET_CHANNEL_WIDTH_COMMAND_NAME, command);
    } else {
      qWarning() << "set_channel_width_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto set_channel_enabled_status_use_case = use_case_factory->createSetChannelEnabledStatusUseCase();
    if (set_channel_enabled_status_use_case != nullptr) {
      auto command = std::make_shared<SetChannelEnabledStatusCommand>(set_channel_enabled_status_use_case);
      command_provider->addCommand(SET_CHANNEL_ENABLED_STATUS_COMMAND_NAME, command);
    } else {
      qWarning() << "set_channel_enabled_status_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto set_channel_inverted_status_use_case = use_case_factory->createSetChannelInvertedStatusUseCase();
    if (set_channel_inverted_status_use_case != nullptr) {
      auto command = std::make_shared<SetChannelInvertedStatusCommand>(set_channel_inverted_status_use_case);
      command_provider->addCommand(SET_CHANNEL_INVERTED_STATUS_COMMAND_NAME, command);
    } else {
      qWarning() << "set_channel_inverted_status_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto set_channel_start_source_use_case = use_case_factory->createSetChannelStartSourceUseCase();
    if (set_channel_start_source_use_case != nullptr) {
      auto command = std::make_shared<SetChannelStartSourceCommand>(set_channel_start_source_use_case);
      command_provider->addCommand(SET_CHANNEL_START_SOURCE_COMMAND_NAME, command);
    } else {
      qWarning() << "set_channel_start_source_use_case is nullptr and cannot be added to command provider " << __func__;
    }

    auto set_channel_start_mode_use_case = use_case_factory->createSetChannelStartModeUseCase();
    if (set_channel_start_mode_use_case != nullptr) {
      auto command = std::make_shared<SetChannelStartModeCommand>(set_channel_start_mode_use_case);
      command_provider->addCommand(SET_CHANNEL_START_MODE_COMMAND_NAME, command);
    } else {
      qWarning() << "set_channel_start_mode_use_case is nullptr and cannot be added to command provider " << __func__;
    }
  }

  return command_provider;
}
