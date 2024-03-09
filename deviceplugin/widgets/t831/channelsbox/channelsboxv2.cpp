#include "channelsboxv2.h"

#include <QLabel>
#include <QHBoxLayout>


ChannelsBoxV2::ChannelsBoxV2(ChannelsCountStrategy *channels_count_strategy, QWidget *parent) : QGroupBox(parent) {
  initUI(channels_count_strategy);
  setConnections();
}

void ChannelsBoxV2::initUI(ChannelsCountStrategy *channels_count_strategy) {
  channels_count_strategy->initUI(&buttons, this);
}

void ChannelsBoxV2::setConnections() {
  for (auto button : buttons)
    QObject::connect(button, &QPushButton::clicked, this, &ChannelsBoxV2::buttonClickedSlot);
}

bool ChannelsBoxV2::hasChosenButton() const {
  return std::any_of(this->buttons.cbegin(), this->buttons.cend(),
                     [](const ChannelButton *bt){return bt->isChosen();});
}

int ChannelsBoxV2::getChannelsCount() const{
  return buttons.size();
}

int ChannelsBoxV2::getCurrentChannelNum() const {
  return current_channel_num;
}

void ChannelsBoxV2::selectChannel(int channel_num) {
  unChoseButtons();
  buttons[channel_num]->setChosen(true);
  current_channel_num = channel_num;
}

void ChannelsBoxV2::unChoseButtons() {
  for (auto button : buttons)
    if (button->isChosen())
      button->setChosen(false);
}

bool ChannelsBoxV2::getOnButtonState(int button_num) const{
  return buttons[button_num]->isOn();
}

void ChannelsBoxV2::setOnButtonState(int button_num, bool enabled) {
  buttons[button_num]->setOn(enabled);
}

bool ChannelsBoxV2::getInvButtonState(int button_num) const{
  return buttons[button_num]->isInverted();
}

void ChannelsBoxV2::setInvButtonState(int button_num, bool inverted) {
  buttons[button_num]->setInvert(inverted);
}

void ChannelsBoxV2::buttonClickedSlot(bool e) {
  auto button = (ChannelButton*)sender();
  if (!button->isChosen()){
    this->unChoseButtons();
    button->setChosen(!button->isChosen());
    current_channel_num = (int) std::distance(buttons.begin(),
                                              std::find(buttons.begin(), buttons.end(), button));
    emit channelChosenActionSignal(current_channel_num);
  }
}
