//
// Created by felis on 02/07/23.
//

#ifndef CRATE_POWER_SUPPLY_WIDGET_CHANNELSCOUNT8STRATEGY_H
#define CRATE_POWER_SUPPLY_WIDGET_CHANNELSCOUNT8STRATEGY_H

#include "channelscountstrategy.h"
#include "deviceplugin/widgets/epss/basic/channelbutton.h"

class ChannelsCount8Strategy : public ChannelsCountStrategy {
public:
    void initUI(std::vector<ChannelButton*> *buttons, QGroupBox *channels_box) override;
};


#endif //CRATE_POWER_SUPPLY_WIDGET_CHANNELSCOUNT8STRATEGY_H
