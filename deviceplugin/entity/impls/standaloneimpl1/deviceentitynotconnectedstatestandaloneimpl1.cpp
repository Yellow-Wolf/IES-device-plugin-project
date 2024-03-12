#include "deviceentitynotconnectedstatestandaloneimpl1.h"
#include "deviceplugin/consts.h"

// TODO: Прописать потом ошибки коннекта

GetChannelDelayResponse DeviceEntityNotConnectedStateStandaloneImpl1::getChannelsDelay(GetChannelDelayRequest request) {
  return GetChannelDelayResponse();
}

int DeviceEntityNotConnectedStateStandaloneImpl1::getChannelCount() {
  return CHANNEL_COUNT;
}

GetSyncModuleStatusesResponse DeviceEntityNotConnectedStateStandaloneImpl1::getSyncModuleStatuses(
    GetSyncModuleStatusesRequest request) {
  return GetSyncModuleStatusesResponse();
}

GetSFPParametersResponse DeviceEntityNotConnectedStateStandaloneImpl1::getSFPParameters(GetSFPParametersRequest request) {
  return GetSFPParametersResponse();
}

GetChannelWidthResponse DeviceEntityNotConnectedStateStandaloneImpl1::getChannelsWidth(GetChannelWidthRequest request) {
  return GetChannelWidthResponse();
}

GetChannelEnabledStatusResponse DeviceEntityNotConnectedStateStandaloneImpl1::getChannelsEnabledStatus(
    GetChannelEnabledStatusRequest request) {
  return GetChannelEnabledStatusResponse();
}

GetChannelInvertedStatusResponse DeviceEntityNotConnectedStateStandaloneImpl1::getChannelsInvertedStatus(
    GetChannelInvertedStatusRequest request) {
  return GetChannelInvertedStatusResponse();
}

GetChannelStartModeResponse DeviceEntityNotConnectedStateStandaloneImpl1::getChannelsStartMode(
    GetChannelStartModeRequest request) {
  return GetChannelStartModeResponse();
}

GetChannelStartSourceResponse DeviceEntityNotConnectedStateStandaloneImpl1::getChannelsStartSource(
    GetChannelStartSourceRequest request) {
  return GetChannelStartSourceResponse();
}
SetChannelDelayResponse DeviceEntityNotConnectedStateStandaloneImpl1::setChannelDelay(SetChannelDelayRequest request) {
  return SetChannelDelayResponse();
}
SetChannelWidthResponse DeviceEntityNotConnectedStateStandaloneImpl1::setChannelWidth(SetChannelWidthRequest request) {
  return SetChannelWidthResponse();
}
SetChannelEnabledStatusResponse DeviceEntityNotConnectedStateStandaloneImpl1::setChannelEnabledStatus(
    SetChannelEnabledStatusRequest request) {
  return SetChannelEnabledStatusResponse();
}
SetChannelInvertedStatusResponse DeviceEntityNotConnectedStateStandaloneImpl1::setChannelInvertedStatus(
    SetChannelInvertedStatusRequest request) {
  return SetChannelInvertedStatusResponse();
}
SetChannelStartSourceResponse DeviceEntityNotConnectedStateStandaloneImpl1::setChannelStartSource(
    SetChannelStartSourceRequest request) {
  return SetChannelStartSourceResponse();
}
SetChannelStartModeResponse DeviceEntityNotConnectedStateStandaloneImpl1::setChannelStartMode(SetChannelStartModeRequest request) {
  return SetChannelStartModeResponse();
}

ErrorCode DeviceEntityNotConnectedStateStandaloneImpl1::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  return DeviceEntityState::loadDeviceDTO(dto);
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityNotConnectedStateStandaloneImpl1::updateDeviceDTO() {
  return DeviceEntityState::updateDeviceDTO();
}

GetInnerStartPeriodResponse DeviceEntityNotConnectedStateStandaloneImpl1::getInnerStartPeriod(GetInnerStartPeriodRequest request) {
  return GetInnerStartPeriodResponse();
}
