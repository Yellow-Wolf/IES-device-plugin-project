#ifndef OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_USECASEFACTORY_H_
#define OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_USECASEFACTORY_H_

#include <memory>

#include <QObject>

#include "deviceplugin/entity/deviceentity.h"

#include "deviceplugin/managementpart/usecase/channel/getchannelscountusecase.h"

#include "deviceplugin/managementpart/usecase/channel/setchannelnameusecase.h"
#include "deviceplugin/managementpart/usecase/channel/setchanneldelayusecase.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelwidthusecase.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelenabledstatususecase.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelinvertedstatususecase.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelstartsourceusecase.h"
#include "deviceplugin/managementpart/usecase/channel/setchannelstartmodeusecase.h"

#include "deviceplugin/managementpart/usecase/channel/getchannelnameusecase.h"
#include "deviceplugin/managementpart/usecase/channel/getchanneldelayusecase.h"
#include "deviceplugin/managementpart/usecase/channel/getchannelwidthusecase.h"
#include "deviceplugin/managementpart/usecase/channel/getchannelenabledstatususecase.h"
#include "deviceplugin/managementpart/usecase/channel/getchannelinvertedstatususecase.h"
#include "deviceplugin/managementpart/usecase/channel/getchannelstartsourceusecase.h"
#include "deviceplugin/managementpart/usecase/channel/getchannelstartmodeusecase.h"


class UseCaseFactory: public QObject {
  Q_OBJECT
 public:
    explicit UseCaseFactory(const std::shared_ptr<DeviceEntity> &device_entity,
                          const std::shared_ptr<IDeviceEntityPoll> &device_entity_poll,
                          QObject *parent = nullptr);

  std::shared_ptr<GetChannelsCountUseCase> createGetChannelsCountUseCase();

  std::shared_ptr<GetChannelNameUseCase> createGetChannelNameUseCase();
  std::shared_ptr<GetChannelDelayUseCase> createGetChannelDelayUseCase();
  std::shared_ptr<GetChannelWidthUseCase> createGetChannelWidthUseCase();
  std::shared_ptr<GetChannelEnabledStatusUseCase> createGetChannelEnabledStatusUseCase();
  std::shared_ptr<GetChannelInvertedStatusUseCase> createGetChannelInvertedStatusUseCase();
  std::shared_ptr<GetChannelStartSourceUseCase> createGetChannelStartSourceUseCase();
  std::shared_ptr<GetChannelStartModeUseCase> createGetChannelStartModeUseCase();

  std::shared_ptr<SetChannelNameUseCase> createSetChannelNameUseCase();
  std::shared_ptr<SetChannelDelayUseCase> createSetChannelDelayUseCase();
  std::shared_ptr<SetChannelWidthUseCase> createSetChannelWidthUseCase();
  std::shared_ptr<SetChannelEnabledStatusUseCase> createSetChannelEnabledStatusUseCase();
  std::shared_ptr<SetChannelInvertedStatusUseCase> createSetChannelInvertedStatusUseCase();
  std::shared_ptr<SetChannelStartSourceUseCase> createSetChannelStartSourceUseCase();
  std::shared_ptr<SetChannelStartModeUseCase> createSetChannelStartModeUseCase();

  // TODO: Дописать методы создания и получения юзкейсов

 private:
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
  std::shared_ptr<IDeviceEntityPoll> _device_entity_poll = nullptr;

  std::shared_ptr<GetChannelsCountUseCase> _get_channels_count_use_case = nullptr;

  std::shared_ptr<SetChannelNameUseCase> _set_channel_name_use_case = nullptr;
  std::shared_ptr<SetChannelDelayUseCase> _set_channel_delay_use_case = nullptr;
  std::shared_ptr<SetChannelWidthUseCase> _set_channel_width_use_case = nullptr;
  std::shared_ptr<SetChannelEnabledStatusUseCase> _set_channel_enabled_status_use_case = nullptr;
  std::shared_ptr<SetChannelInvertedStatusUseCase> _set_channel_inverted_status_use_case = nullptr;
  std::shared_ptr<SetChannelStartSourceUseCase> _set_channel_start_source_use_case = nullptr;
  std::shared_ptr<SetChannelStartModeUseCase> _set_channel_start_mode_use_case = nullptr;

  std::shared_ptr<GetChannelNameUseCase> _get_channel_name_use_case = nullptr;
  std::shared_ptr<GetChannelDelayUseCase> _get_channel_delay_use_case = nullptr;
  std::shared_ptr<GetChannelWidthUseCase> _get_channel_width_use_case = nullptr;
  std::shared_ptr<GetChannelEnabledStatusUseCase> _get_channel_enabled_status_use_case = nullptr;
  std::shared_ptr<GetChannelInvertedStatusUseCase> _get_channel_inverted_status_use_case = nullptr;
  std::shared_ptr<GetChannelStartSourceUseCase> _get_channel_start_source_use_case = nullptr;
  std::shared_ptr<GetChannelStartModeUseCase> _get_channel_start_mode_use_case = nullptr;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_MANAGEMENTPART_USECASE_USECASEFACTORY_H_
