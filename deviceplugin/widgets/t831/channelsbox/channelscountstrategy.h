#ifndef SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNTSTRATEGY_H
#define SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNTSTRATEGY_H

#include "deviceplugin/stylesheets/default.h"
#include "deviceplugin/consts.h"
#include "deviceplugin/widgets/epss/basic/channelbutton.h"

#include <string>

#include <QGroupBox>
#include <QEvent>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QGroupBox>


class ChannelsCountStrategy {
public:
  virtual void initUI(std::vector<ChannelButton*> *buttons, QGroupBox *channels_box) = 0;

  int getChannelsCount();

protected:
  int channels_count = 0;
};


#endif //SYNC_SYS_DEVICE_WIDGET_CHANNELSCOUNTSTRATEGY_H
