//
// Created by felis on 05/02/23.
//

#include <QGridLayout>
#include "t831settingswidget.h"
#include "deviceplugin/consts.h"
#include "deviceplugin/enums.h"
#include <QDebug>


T831SettingsWidget::T831SettingsWidget(const QString &caption, QWidget *parent) : QGroupBox(caption, parent) {
    initUI(caption);
    setConnections();
}

void T831SettingsWidget::initUI(const QString &caption) {
    setTitle(caption);
    setFont(header_group_box_font);

    auto *main_layout = new QGridLayout(this);

    clock_combobox = new ComboBoxWithLabel("CLOCK", t831_modes, this);

    start_combobox = new ComboBoxWithLabel("Запуск", t831_modes, this);

    period_time_input = new FullComposedTimeInput("Период", 0, 10e12, 0, 10e9, 0, 10e6, this);

    duration_time_input = new FullComposedTimeInput("Длительность", 0, 10e12, 0, 10e9, 0, 10e6, this);

    inclusion_state_button = new StateButtonWithLabel("Включение");

    inversion_state_button = new StateButtonWithLabel("Инверсия");

    main_layout->addWidget(clock_combobox, 0, 0);
    main_layout->addWidget(start_combobox, 1, 0);
    main_layout->addWidget(period_time_input, 0, 1, 2, 1);
    main_layout->addWidget(duration_time_input, 0, 2, 2, 1);
    main_layout->addWidget(inclusion_state_button, 0, 3);
    main_layout->addWidget(inversion_state_button, 1, 3);
}

int T831SettingsWidget::getClockState() {
    return clock_combobox->getState();
}

void T831SettingsWidget::setClockState(int state) {
    clock_combobox->setState(state);
}

int T831SettingsWidget::getStartState() {
    return start_combobox->getState();
}

void T831SettingsWidget::setStartState(int16_t state) {
    start_combobox->setState(state);
}

void T831SettingsWidget::setConnections() {
    QObject::connect(clock_combobox, &ComboBoxWithLabel::stateChanged,
                     this, &T831SettingsWidget::clockStateChanged);
    QObject::connect(start_combobox, &ComboBoxWithLabel::stateChanged,
                     this, &T831SettingsWidget::startStateChanged);
    QObject::connect(period_time_input, &FullComposedTimeInput::writeButtonClicked,
                     this, &T831SettingsWidget::periodTimeChanged);
    QObject::connect(duration_time_input, &FullComposedTimeInput::writeButtonClicked,
                     this, &T831SettingsWidget::durationTimeChanged);
    QObject::connect(period_time_input, &FullComposedTimeInput::readButtonClicked,
                     this, &T831SettingsWidget::periodTimeRead);
    QObject::connect(duration_time_input, &FullComposedTimeInput::readButtonClicked,
                     this, &T831SettingsWidget::durationTimeRead);
    QObject::connect(inclusion_state_button, &StateButtonWithLabel::stateChanged,
                     this, &T831SettingsWidget::inclusionStateChanged);
    QObject::connect(inversion_state_button, &StateButtonWithLabel::stateChanged,
                     this, &T831SettingsWidget::inversionStateChanged);
}

void T831SettingsWidget::setStartPeriod(const QString &period) {
    setStartPeriod(period.toULongLong());
}

void T831SettingsWidget::setStartPeriod(uint64_t value) {
    period_time_input->setValue(value);
}

uint64_t T831SettingsWidget::getStartPeriod() const {
    return period_time_input->getValue();
}

void T831SettingsWidget::setStartWidth(const QString &width) {
    setStartWidth(width.toULongLong());
}

void T831SettingsWidget::setStartWidth(uint64_t value) {
    duration_time_input->setValue(value);
}

uint64_t T831SettingsWidget::getStartWidth() const {
    return duration_time_input->getValue();
}

bool T831SettingsWidget::getStartEnabled() {
    return inclusion_state_button->getState();
}

void T831SettingsWidget::setStartEnabled(bool enabled) {
    inclusion_state_button->setState(enabled);
}

bool T831SettingsWidget::getStartInverted() {
    return inversion_state_button->getState();
}

void T831SettingsWidget::setStartInverted(bool inverted) {
    inversion_state_button->setState(inverted);
}


