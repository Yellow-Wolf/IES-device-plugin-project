#include "channelsettings.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>


ChannelSettings::ChannelSettings(QWidget *parent) : QGroupBox(parent) {
  initUI();
  setConnections();
  checkSaveChangesButtonEnabled();
}

void ChannelSettings::setDelay(const QString &delay) {
  delay_input_spin_box->setText(delay);
}

bool ChannelSettings::getDelay(double time, Units unit) {
  return delay_input_spin_box->getValueAndUnit(time, unit);
}

void ChannelSettings::setWidth(const QString &width) {
  width_input_spin_box->setText(width);
}

bool ChannelSettings::getWidth(double time, Units unit) {
  return width_input_spin_box->getValueAndUnit(time, unit);
}

void ChannelSettings::checkSaveChangesButtonEnabled() {
  this->save_changes_button->setEnabled(width_input_spin_box->getValidationState() == QValidator::Acceptable &&
                                        delay_input_spin_box->getValidationState() == QValidator::Acceptable);
}

void ChannelSettings::packDelayWidthValues() {
  uint64_t delay = 0;
  uint64_t width = 0;
  delay_input_spin_box->getTimeInNano(delay);
  width_input_spin_box->getTimeInNano(width);
  emit saveChangesButtonClicked(delay, width);
}

void ChannelSettings::initUI() {
  setTitle(block_name);

  width_input_spin_box = new TimeInputSpinBox(this);
  delay_input_spin_box = new TimeInputSpinBox(this);
  auto *width_label = new QLabel("Длительность импульса:", this);
  auto *delay_label = new QLabel("Задержка импульса:", this);

  auto *main_layout = new QGridLayout(this);
  main_layout->setAlignment(Qt::AlignCenter);

  main_layout->addWidget(width_label, 0, 0, 1, 2);
  main_layout->addWidget(width_input_spin_box, 1, 0, 1, 2);
  main_layout->addWidget(delay_label, 2, 0, 1, 2);
  main_layout->addWidget(delay_input_spin_box, 3, 0, 1, 2);

  on_off_button = new QPushButton("Вкл", this);
  invert_button = new QPushButton("Инверсия", this);
  save_changes_button = new QPushButton("Записать изменения", this);
  save_changes_button->setEnabled(false);

  main_layout->addWidget(save_changes_button, 4, 0, 1, 2);
  main_layout->addWidget(on_off_button, 5, 0);
  main_layout->addWidget(invert_button, 5, 1);
}

void ChannelSettings::setConnections() {
  QObject::connect(this->on_off_button, &QAbstractButton::released,
                   this, &ChannelSettings::onOffButtonClicked);
  QObject::connect(this->invert_button, &QAbstractButton::released,
                   this, &ChannelSettings::invertButtonClicked);
  QObject::connect(this->width_input_spin_box, &TimeInputSpinBox::validationStateChanged,
                   this, &ChannelSettings::checkSaveChangesButtonEnabled);
  QObject::connect(this->delay_input_spin_box, &TimeInputSpinBox::validationStateChanged,
                   this, &ChannelSettings::checkSaveChangesButtonEnabled);
  QObject::connect(this->save_changes_button, &QPushButton::released,
                   this, &ChannelSettings::packDelayWidthValues);
}
