#include "innerstartsettingswidget.h"

#include <QHBoxLayout>


// ---------------------- Инициализация виджета -------------------------------

InnerStartSettingsWidget::InnerStartSettingsWidget(QWidget *parent): QGroupBox(tr("Управление внутренним запуском"),parent) {
  initUI();
  setConnections();
}

void InnerStartSettingsWidget::initUI() {
  setFont(QFont("Segoe UI", 16));

  auto *main_layout = new QHBoxLayout(this);

  period_input = new FullComposedTimeInput(tr("Период"),100, 10e12, 0, 10e9, 0, 10e6, this);
  width_input = new FullComposedTimeInput(tr("Длительность"), 100, 10e12, 0, 10e9, 0, 10e6, this);

  on_button = new StateButton(tr("Выкл"), Qt::green, tr("Вкл"), Qt::white);
  inv_button = new StateButton(tr("Инв"), Qt::green, tr("Инв"), Qt::white);

  period_input->setContentsMargins(0, 0, 0, 0);
  width_input->setContentsMargins(0, 0, 0, 0);

  on_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
  inv_button->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

  main_layout->addWidget(period_input);
  main_layout->addWidget(width_input);

  main_layout->addWidget(on_button);
  main_layout->addWidget(inv_button);

  main_layout->setSizeConstraint(QLayout::SetMaximumSize);
}

// ------- Установка коннектов и методы, через которые проходят сигналы -------

void InnerStartSettingsWidget::setConnections() {
  QObject::connect(on_button, &StateButton::released,
                   this, &InnerStartSettingsWidget::onStatusChangedProxySlot);
  QObject::connect(inv_button, &StateButton::released,
                   this, &InnerStartSettingsWidget::invStatusChangedProxySlot);

  QObject::connect(period_input, &FullComposedTimeInput::readButtonClicked,
                   this, &InnerStartSettingsWidget::readPeriodButtonClicked);
  QObject::connect(width_input, &FullComposedTimeInput::readButtonClicked,
                   this, &InnerStartSettingsWidget::readWidthButtonClicked);

  QObject::connect(period_input, &FullComposedTimeInput::writeButtonClicked,
                   this, &InnerStartSettingsWidget::writeButtonClickedProxySlot);
  QObject::connect(width_input, &FullComposedTimeInput::writeButtonClicked,
                   this, &InnerStartSettingsWidget::writeButtonClickedProxySlot);
}

void InnerStartSettingsWidget::onStatusChangedProxySlot() {
  emit onStatusChanged(getOnButtonState());
}

void InnerStartSettingsWidget::invStatusChangedProxySlot() {
  emit invStatusChanged(getInvButtonState());
}

void InnerStartSettingsWidget::writeButtonClickedProxySlot() {
  if (sender() == period_input)
    emit writePeriodButtonClicked(getInnerStartPeriod());
  else
    emit writeWidthButtonClicked(getInnerStartWidth());
}

// -------- Вспомогательные приватные методы для геттеров и сеттеров ----------


// -------------------------- Геттеры и сеттеры -------------------------------

void InnerStartSettingsWidget::setOnButtonState(bool state) {
  on_button->setState(state);
}

bool InnerStartSettingsWidget::getOnButtonState() const {
  return on_button->getState();
}

void InnerStartSettingsWidget::setInvButtonState(bool state) {
  inv_button->setState(state);
}

bool InnerStartSettingsWidget::getInvButtonState() const {
  return inv_button->getState();
}

void InnerStartSettingsWidget::setInnerStartPeriod(const QString &period) {
  setInnerStartPeriod(period.toULongLong());
}

void InnerStartSettingsWidget::setInnerStartPeriod(uint64_t value) {
  period_input->setValue(value);
}

uint64_t InnerStartSettingsWidget::getInnerStartPeriod() const {
  return period_input->getValue();
}

void InnerStartSettingsWidget::setInnerStartWidth(const QString &width) {
  setInnerStartWidth(width.toULongLong());
}

void InnerStartSettingsWidget::setInnerStartWidth(uint64_t value) {
  width_input->setValue(value);
}

uint64_t InnerStartSettingsWidget::getInnerStartWidth() const {
  return width_input->getValue();
}
