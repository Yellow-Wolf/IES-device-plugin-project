#include "fullchannelsettingst831.h"

#include "deviceplugin/consts.h"

#include <QButtonGroup>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QMap>

#include <QDebug>


// ---------------------- Инициализация виджета -------------------------------

FullChannelSettingsT831::FullChannelSettingsT831(QWidget *parent): QGroupBox(tr("Настройки канала"), parent) {
  initUI();
  setConnections();
}

void FullChannelSettingsT831::initUI() {
  setFont(header_group_box_font);
  auto *main_layout = new QVBoxLayout(this);
  //auto *input_signal_management_layout = new QGridLayout;

  name_input_ledit = new FullComposedLineEdit("Название канала:", this, Qt::Horizontal);
  main_layout->addWidget(name_input_ledit);

  from_start_group_box = new QGroupBox(tr("Настройка задержанного импульса"));
  auto *time_params_management_layout = new QGridLayout(from_start_group_box);
  auto *channel_params_management_layout = new QHBoxLayout;

  delay_input = new FullComposedTimeInput(tr("Задержка"), 0, 10e12, 0, 10e9, 0, 10e6, this);
  width_input = new FullComposedTimeInput(tr("Длительность"), 0, 10e12, 0, 10e9, 0, 10e6, this);

  on_button = new StateButton(tr("Выкл"), Qt::green, tr("Вкл"), Qt::white, this);
  inv_button = new StateButton(tr("Инв"), Qt::green, tr("Инв"), Qt::white, this);


  //on_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  //inv_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  //start_des_combobox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);


  //start_mode_radio_buttons_layout->addWidget(proxy_start_radio_button, 0, 0);
  //start_mode_radio_buttons_layout->addWidget(from_start_radio_button, 1, 0);

  //input_signal_management_layout->addWidget(new StandardPropertyLabel(tr("Источник запуска"), 14, this), 0, 0);
  //input_signal_management_layout->addWidget(start_des_combobox, 0, 1);

  time_params_management_layout->addWidget(delay_input, 0, 0);
  time_params_management_layout->addWidget(width_input, 0, 1);
  channel_params_management_layout->addWidget(on_button);
  channel_params_management_layout->addWidget(inv_button);
  time_params_management_layout->addLayout(channel_params_management_layout, 1, 0, 1, 2);

  from_start_group_box->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

  from_start_group_box->setLayout(time_params_management_layout);

  //main_layout->addLayout(input_signal_management_layout);
  //main_layout->addLayout(time_params_management_layout);
  main_layout->addWidget(from_start_group_box);
//  main_layout->addLayout(channel_params_management_layout);

}

// ------- Установка коннектов и методы, через которые проходят сигналы -------

void FullChannelSettingsT831::setConnections() {
  QObject::connect(name_input_ledit, &FullComposedLineEdit::getValueActionSignal,
                   this, &FullChannelSettingsT831::getChannelNameActionSignal);
  QObject::connect(name_input_ledit, &FullComposedLineEdit::valueChangedSignal,
                   this, &FullChannelSettingsT831::channelNameChangedSignal);

  QObject::connect(on_button, &StateButton::released,
                   this, &FullChannelSettingsT831::onStatusChangedProxySlot);
  QObject::connect(inv_button, &StateButton::released,
                   this, &FullChannelSettingsT831::invStatusChangedProxySlot);

  QObject::connect(delay_input, &FullComposedTimeInput::readButtonClicked,
                   this, &FullChannelSettingsT831::readDelayButtonClicked);
  QObject::connect(width_input, &FullComposedTimeInput::readButtonClicked,
                   this, &FullChannelSettingsT831::readWidthButtonClicked);

  QObject::connect(delay_input, &FullComposedTimeInput::writeButtonClicked,
                   this, &FullChannelSettingsT831::writeButtonClickedProxySlot);
  QObject::connect(width_input, &FullComposedTimeInput::writeButtonClicked,
                   this, &FullChannelSettingsT831::writeButtonClickedProxySlot);

}

void FullChannelSettingsT831::onStatusChangedProxySlot() {
  emit onStatusChanged(getOnButtonState());
}

void FullChannelSettingsT831::invStatusChangedProxySlot() {
  emit invStatusChanged(getInvButtonState());
}

void FullChannelSettingsT831::writeButtonClickedProxySlot() {
  if (sender() == delay_input)
      emit writeDelayButtonClicked(getChannelDelayValue());
  else
      emit writeWidthButtonClicked(getChannelWidthValue());
}

// -------------------------- Геттеры и сеттеры -------------------------------

void FullChannelSettingsT831::setCurrentChannelNum(const QString &channel_const_name, const QString &channel_name) {
  setTitle(QString(tr("Настройки канала %1 (%2)")).arg(channel_name).arg(channel_const_name));
}

void FullChannelSettingsT831::setChannelName(const QString &text) {
  name_input_ledit->setValue(text);
}

QString FullChannelSettingsT831::getChannelName() {
  return name_input_ledit->getValue();
}

void FullChannelSettingsT831::setOnButtonState(bool state) {
  on_button->setState(state);
}

bool FullChannelSettingsT831::getOnButtonState() const {
  return on_button->getState();
}

void FullChannelSettingsT831::setInvButtonState(bool state) {
  inv_button->setState(state);
}

bool FullChannelSettingsT831::getInvButtonState() const {
  return inv_button->getState();
}

void FullChannelSettingsT831::setChannelDelay(const QString &delay) {
  setChannelDelay(delay.toULongLong());
}

void FullChannelSettingsT831::setChannelDelay(uint64_t value) {
  delay_input->setValue(value);
}

uint64_t FullChannelSettingsT831::getChannelDelayValue() const {
  return delay_input->getValue();
}

void FullChannelSettingsT831::setChannelWidth(const QString &width) {
  setChannelWidth(width.toULongLong());
}

void FullChannelSettingsT831::setChannelWidth(uint64_t value) {
  width_input->setValue(value);
}

uint64_t FullChannelSettingsT831::getChannelWidthValue() const {
  return width_input->getValue();
}

