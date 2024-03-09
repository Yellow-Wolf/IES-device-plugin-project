#include "fullchannelsettings.h"

#include "deviceplugin/consts.h"

#include <QButtonGroup>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QMap>

#include <QDebug>


// ---------------------- Инициализация виджета -------------------------------

FullChannelSettings::FullChannelSettings(const QMap<int, QString>& start_names, bool ck1,
                                         QWidget *parent): QGroupBox(tr("Настройки канала"), parent) {
  initUI(start_names, ck1);
  setConnections();
}

void FullChannelSettings::initUI(const QMap<int, QString>& start_names, bool ck1) {
  setFont(header_group_box_font);
  auto *main_layout = new QVBoxLayout(this);
  auto *input_signal_management_layout = new QGridLayout;

  name_input_ledit = new FullComposedLineEdit("Название канала:", this, Qt::Horizontal);
  main_layout->addWidget(name_input_ledit);

  auto *start_mode_radio_buttons_group_box = new QGroupBox(tr("Режим работы канала"));
  input_signal_management_layout->addWidget(start_mode_radio_buttons_group_box, 1, 0, 1, 2);
  auto *start_mode_radio_buttons_layout = new QGridLayout(start_mode_radio_buttons_group_box);


  from_start_group_box = new QGroupBox(tr("Настройка задержанного импульса"));
  auto *time_params_management_layout = new QGridLayout(from_start_group_box);
  auto *channel_params_management_layout = new QHBoxLayout;

  auto *start_mode_group = new QButtonGroup(this);
  from_start_radio_button = new QRadioButton(tr("Задержанный импульс"), this);
  proxy_start_radio_button = new QRadioButton(tr("Запускающий импульс"), this);
  start_mode_group->addButton(from_start_radio_button);
  start_mode_group->addButton(proxy_start_radio_button);

  start_des_combobox = new StandardUShortCombobox(start_names, this);

  delay_input = new FullComposedTimeInput(tr("Задержка"), 0, 10e12, 0, 10e9, 0, 10e6, this);
  width_input = new FullComposedTimeInput(tr("Длительность"), 0, 10e12, 0, 10e9, 0, 10e6, this);
  if (ck1){
      delay_module_input = new FullComposedTimeInput(tr("Подстройка"), 0, 10e12, 0, 10e9, 0, 10e6, this);
  }

  on_button = new StateButton(tr("Выкл"), Qt::green, tr("Вкл"), Qt::white, this);
  inv_button = new StateButton(tr("Инв"), Qt::green, tr("Инв"), Qt::white, this);


  proxy_start_radio_button->setFont(default_font);
  from_start_radio_button->setFont(default_font);
  from_start_group_box->setFont(default_font);
  start_mode_radio_buttons_group_box->setFont(default_font);

  on_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  inv_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  start_des_combobox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);


  start_mode_radio_buttons_layout->addWidget(proxy_start_radio_button, 0, 0);
  start_mode_radio_buttons_layout->addWidget(from_start_radio_button, 1, 0);

  input_signal_management_layout->addWidget(new StandardPropertyLabel(tr("Источник запуска"), 14, this), 0, 0);
  input_signal_management_layout->addWidget(start_des_combobox, 0, 1);

  time_params_management_layout->addWidget(delay_input, 0, 0);
  time_params_management_layout->addWidget(width_input, 0, 1);

  if (ck1){
      time_params_management_layout->addWidget(delay_module_input, 0, 2);
  }
  channel_params_management_layout->addWidget(on_button);
  channel_params_management_layout->addWidget(inv_button);
  time_params_management_layout->addLayout(channel_params_management_layout, 1, 0, 1, 2);

  main_layout->addLayout(input_signal_management_layout);
  main_layout->addWidget(from_start_group_box);
//  main_layout->addLayout(channel_params_management_layout);

  channel_params_management_layout->setAlignment(Qt::AlignCenter);
  channel_params_management_layout->setSizeConstraint(QLayout::SetMaximumSize);
}

// ------- Установка коннектов и методы, через которые проходят сигналы -------

void FullChannelSettings::setConnections() {
  QObject::connect(name_input_ledit, &FullComposedLineEdit::getValueActionSignal,
                   this, &FullChannelSettings::getChannelNameActionSignal);
  QObject::connect(name_input_ledit, &FullComposedLineEdit::valueChangedSignal,
                   this, &FullChannelSettings::channelNameChangedSignal);

  QObject::connect(start_des_combobox, &StandardUShortCombobox::stateChanged,
                   this, &FullChannelSettings::startSourceChangedSignal);
  QObject::connect(from_start_radio_button, &QRadioButton::released,
                   this, &FullChannelSettings::fromStartSelectedSignal);
  QObject::connect(proxy_start_radio_button, &QRadioButton::released,
                   this, &FullChannelSettings::proxyStartSelectedSignal);

  QObject::connect(on_button, &StateButton::released,
                   this, &FullChannelSettings::onStatusChangedProxySlot);
  QObject::connect(inv_button, &StateButton::released,
                   this, &FullChannelSettings::invStatusChangedProxySlot);

  QObject::connect(delay_input, &FullComposedTimeInput::readButtonClicked,
                   this, &FullChannelSettings::readDelayButtonClicked);
  QObject::connect(width_input, &FullComposedTimeInput::readButtonClicked,
                   this, &FullChannelSettings::readWidthButtonClicked);

  QObject::connect(delay_input, &FullComposedTimeInput::writeButtonClicked,
                   this, &FullChannelSettings::writeButtonClickedProxySlot);
  QObject::connect(width_input, &FullComposedTimeInput::writeButtonClicked,
                   this, &FullChannelSettings::writeButtonClickedProxySlot);
}

void FullChannelSettings::onStatusChangedProxySlot() {
  emit onStatusChanged(!getOnButtonState());
}

void FullChannelSettings::invStatusChangedProxySlot() {
  emit invStatusChanged(getInvButtonState());
}

void FullChannelSettings::writeButtonClickedProxySlot() {
  if (sender() == delay_input)
      emit writeDelayButtonClicked(getChannelDelayValue());
  else
      emit writeWidthButtonClicked(getChannelWidthValue());
}

// -------------------------- Геттеры и сеттеры -------------------------------

void FullChannelSettings::setFromStartMode() {
  from_start_radio_button->blockSignals(true);
  proxy_start_radio_button->blockSignals(true);

  from_start_radio_button->setChecked(true);
  delay_input->setEnabled(true);
  width_input->setEnabled(true);
  qDebug() << "from start toggled";

  from_start_radio_button->blockSignals(false);
  proxy_start_radio_button->blockSignals(false);
}


void FullChannelSettings::setProxyMode() {
  from_start_radio_button->blockSignals(true);
  proxy_start_radio_button->blockSignals(true);

  proxy_start_radio_button->setChecked(true);
  delay_input->setEnabled(false);
  width_input->setEnabled(false);

  from_start_radio_button->blockSignals(false);
  proxy_start_radio_button->blockSignals(false);
}

void FullChannelSettings::setCurrentChannelNum(const QString &channel_const_name, const QString &channel_name) {
  setTitle(QString(tr("Настройки канала %1 (%2)")).arg(channel_name).arg(channel_const_name));
}

void FullChannelSettings::setChannelName(const QString &text) {
  name_input_ledit->setValue(text);
}

QString FullChannelSettings::getChannelName() {
  return name_input_ledit->getValue();
}

int FullChannelSettings::getStartSource() {
  return start_des_combobox->getState();
}

void FullChannelSettings::setStartSource(int des_num) {
  start_des_combobox->blockSignals(true);
  start_des_combobox->setCurrentIndex(des_num);
  start_des_combobox->blockSignals(false);
}

void FullChannelSettings::setOnButtonState(bool state) {
  on_button->setState(state);
}

bool FullChannelSettings::getOnButtonState() const {
  return on_button->getState();
}

void FullChannelSettings::setInvButtonState(bool state) {
  inv_button->setState(state);
}

bool FullChannelSettings::getInvButtonState() const {
  return inv_button->getState();
}

void FullChannelSettings::setChannelDelay(const QString &delay) {
  setChannelDelay(delay.toULongLong());
}

void FullChannelSettings::setChannelDelay(uint64_t value) {
  delay_input->setValue(value);
}

uint64_t FullChannelSettings::getChannelDelayValue() const {
  return delay_input->getValue();
}

void FullChannelSettings::setChannelWidth(const QString &width) {
  setChannelWidth(width.toULongLong());
}

void FullChannelSettings::setChannelWidth(uint64_t value) {
  width_input->setValue(value);
}

uint64_t FullChannelSettings::getChannelWidthValue() const {
  return width_input->getValue();
}

void FullChannelSettings::updateChannelSettings(const ChannelViewData &channel_data) {
  setChannelName(channel_data.channel_name);

  setChannelDelay(channel_data.channel_delay_value);
  setChannelWidth(channel_data.channel_width_value);

  setOnButtonState(channel_data.enabled_status);
  setInvButtonState(channel_data.inverted_status);

  setStartSource(channel_data.start_source_value);

  switch (channel_data.start_mode_value) {
    case START:
      setFromStartMode();
      break;
    case PROXY:
      setProxyMode();
      break;
  }
}

