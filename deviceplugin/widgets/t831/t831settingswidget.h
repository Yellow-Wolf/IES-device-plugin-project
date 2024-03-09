//
// Created by felis on 05/02/23.
//

#ifndef CRATE_POWER_SUPPLY_WIDGET_T831SETTINGSWIDGET_H
#define CRATE_POWER_SUPPLY_WIDGET_T831SETTINGSWIDGET_H


#include <QGroupBox>

#include <widgets/common/composed/fullcomposedtimeinput.h>

#include "comboboxwithlabel.h"
#include "statebuttonwithlabel.h"

class T831SettingsWidget : public QGroupBox{
    Q_OBJECT
public:
    explicit T831SettingsWidget(const QString &caption,
                                QWidget *parent = nullptr);
    int getClockState();
    void setClockState(int state);
    int getStartState();
    void setStartState(int16_t state);

    void setStartPeriod(const QString &period);
    void setStartPeriod(uint64_t value);
    uint64_t getStartPeriod() const;

    void setStartWidth(const QString &width);
    void setStartWidth(uint64_t value);
    uint64_t getStartWidth() const;

    bool getStartEnabled();
    void setStartEnabled(bool enabled);

    bool getStartInverted();
    void setStartInverted(bool inverted);

signals:
    void clockStateChanged(int state);
    void startStateChanged(int state);
    void periodTimeChanged(uint64_t value);
    void durationTimeChanged(uint64_t value);
    void periodTimeRead();
    void durationTimeRead();
    void inclusionStateChanged(bool state);
    void inversionStateChanged(bool state);

private:
    ComboBoxWithLabel *clock_combobox;
    ComboBoxWithLabel *start_combobox;
    FullComposedTimeInput *period_time_input;
    FullComposedTimeInput *duration_time_input;
    StateButtonWithLabel *inclusion_state_button;
    StateButtonWithLabel *inversion_state_button;

    void initUI(const QString &caption);
    void setConnections();
};


#endif //CRATE_POWER_SUPPLY_WIDGET_T831SETTINGSWIDGET_H
