#ifndef SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNT12STRATEGY_H
#define SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNT12STRATEGY_H

#include "channelscountstrategy.h"


class ChannelsCount12Strategy : public ChannelsCountStrategy {
public:
    void initUI(std::vector<ChannelButton*> *buttons, QGroupBox *channels_box) override;
};


#endif //SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNT12STRATEGY_H
