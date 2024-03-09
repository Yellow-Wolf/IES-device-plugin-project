//
// Created by felis on 05/02/23.
//

#ifndef CRATE_POWER_SUPPLY_WIDGET_STATEBUTTONWITHLABEL_H
#define CRATE_POWER_SUPPLY_WIDGET_STATEBUTTONWITHLABEL_H


#include <QWidget>
#include <QLabel>

#include <widgets/common/basic/statebutton.h>

class StateButtonWithLabel : public QWidget{
    Q_OBJECT
public:
    explicit StateButtonWithLabel(const QString &caption,
                                  QWidget *parent = nullptr);
    StateButtonWithLabel(QWidget *parent = nullptr);

    bool getState();
    void setState(bool state);

    signals:
    void stateChanged(bool state);

private:
    QLabel *name_label;
    StateButton *main_button;

    void initUI(const QString &caption);
    void setConnections();
};


#endif //CRATE_POWER_SUPPLY_WIDGET_STATEBUTTONWITHLABEL_H
