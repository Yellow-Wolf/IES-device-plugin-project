#ifndef SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNT24STRATEGY_H
#define SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNT24STRATEGY_H

#include "channelscountstrategy.h"


class ChannelsCount24Strategy : public ChannelsCountStrategy {
public:
    void initUI(std::vector<ChannelButton*> *buttons, QGroupBox *channels_box) override;
};


#endif //SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNT24STRATEGY_H
