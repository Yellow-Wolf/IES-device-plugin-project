#include "channelbutton.h"

#include "deviceplugin/stylesheets/default.h"
#include "deviceplugin/consts.h"


ChannelButton::ChannelButton(const QString &button_name, QWidget *parent) : QPushButton(parent) {
  initUI(button_name);
}

void ChannelButton::changeStyleSheet() {
  QString new_style_sheet = "";

  new_style_sheet.append(ChannelButtonStyles[switched ? ChannelButtonStates::BUTTON_ON :
                                                      ChannelButtonStates::BUTTON_OFF]);
  new_style_sheet.append(inverted ? ChannelButtonStyles[ChannelButtonStates::BUTTON_INVERTED] : "");
  new_style_sheet.append(chosen ? ChannelButtonStyles[ChannelButtonStates::BUTTON_CHOSEN]: "");

  setStyleSheet(new_style_sheet);
}

void ChannelButton::setOn(bool switched) {
  if (switched != this->switched){
    this->switched = switched;
    this->changeStyleSheet();
  }
}

bool ChannelButton::isOn() const {
  return this->switched;
}

void ChannelButton::setInvert(bool inverted) {
  if (inverted != this->inverted){
    this->inverted = inverted;
    this->changeStyleSheet();
  }
}

bool ChannelButton::isInverted() const {
  return this->inverted;
}

void ChannelButton::setChosen(bool chosen) {
  if (chosen != this->chosen){
    this->chosen = chosen;
    this->changeStyleSheet();
  }
}

bool ChannelButton::isChosen() const {
  return this->chosen;
}

void ChannelButton::initUI(const QString &button_name) {
  setFont(default_font);
  setText(button_name);
  setFixedSize(100, 40);
}
