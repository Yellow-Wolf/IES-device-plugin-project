//
// Created by felis on 05/02/23.
//

#ifndef CRATE_POWER_SUPPLY_WIDGET_COMBOBOXWITHLABEL_H
#define CRATE_POWER_SUPPLY_WIDGET_COMBOBOXWITHLABEL_H


#include <QWidget>
#include <QLabel>
#include <widgets/common/basic/standardcombobox.h>

class ComboBoxWithLabel  : public QWidget{
    Q_OBJECT
public:
    explicit ComboBoxWithLabel(const QString &caption,
                               const QMap<int, QString>& states,
                               QWidget *parent = nullptr);
    ComboBoxWithLabel(QWidget *parent = nullptr);

    int getState();
    void setState(int16_t state);

    void updateStates(const QMap<int, QString> &states, int current_state = 0);

signals:
    void stateChanged(int state);

private:
    QLabel *name_label;
    StandardUShortCombobox *main_combobox;

    void initUI(const QString &caption, const QMap<int, QString> &states);
    void setConnections();
};


#endif //CRATE_POWER_SUPPLY_WIDGET_COMBOBOXWITHLABEL_H
