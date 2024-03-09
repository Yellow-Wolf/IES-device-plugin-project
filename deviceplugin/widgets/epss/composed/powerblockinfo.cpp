#include "powerblockinfo.h"

#include <QGridLayout>
#include <QLabel>


PowerBlockInfo::PowerBlockInfo(QWidget *parent) : QGroupBox(parent) {
  initUI();
}

void PowerBlockInfo::setRfJoinState(LampStates state) {

}

LampStates PowerBlockInfo::getRfJoinState() const {
  return LAMP_OFF;
}

void PowerBlockInfo::setSyncJoinState(LampStates state) {

}

LampStates PowerBlockInfo::getSyncJoinState() const {
  return LAMP_OFF;
}

void PowerBlockInfo::setRfInState(LampStates state) {

}

LampStates PowerBlockInfo::getRfInState() const {
  return LAMP_OFF;
}

void PowerBlockInfo::setSyncInState(LampStates state) {

}

LampStates PowerBlockInfo::getSyncInState() const {
  return LAMP_OFF;
}

void PowerBlockInfo::setRfOutState(LampStates state) {

}

LampStates PowerBlockInfo::getRfOutState() const {
  return LAMP_OFF;
}

void PowerBlockInfo::setSyncOutState(LampStates state) {

}

LampStates PowerBlockInfo::getSyncOutState() const {
  return LAMP_OFF;
}

void PowerBlockInfo::initUI() {
  auto *main_layout = new QGridLayout(this);
  this->setTitle("Состояние модулей");

  auto *rf_name_label = new QLabel("RF", this);
  auto *sync_name_label = new QLabel("SYNC", this);
  auto *connect_label = new QLabel("Connect", this);
  auto *in_label = new QLabel("In", this);
  auto *out_label = new QLabel("Out", this);

  main_layout->addWidget(rf_name_label, 1, 0);
  main_layout->addWidget(sync_name_label, 2, 0);
  main_layout->addWidget(connect_label, 0, 1);
  main_layout->addWidget(in_label, 0, 2);
  main_layout->addWidget(out_label, 0, 3);

  rf_join_lamp = new LampWidget(this);
  sync_join_lamp = new LampWidget(this);
  rf_in_lamp = new LampWidget(this);
  sync_in_lamp = new LampWidget(this);
  rf_out_lamp = new LampWidget(this);
  sync_out_lamp = new LampWidget(this);

  main_layout->addWidget(rf_join_lamp, 1, 1);
  main_layout->addWidget(sync_join_lamp, 2, 1);
  main_layout->addWidget(rf_in_lamp, 1, 2);
  main_layout->addWidget(sync_in_lamp, 2, 2);
  main_layout->addWidget(rf_out_lamp, 1, 3);
  main_layout->addWidget(sync_out_lamp, 2, 3);
}
