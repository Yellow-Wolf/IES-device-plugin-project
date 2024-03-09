//
// Created by felis on 05/02/23.
//

#include <QGridLayout>
#include "statebuttonwithlabel.h"
#include "deviceplugin/consts.h"

StateButtonWithLabel::StateButtonWithLabel(const QString &caption, QWidget *parent) {
    initUI(caption);
    setConnections();
}

void StateButtonWithLabel::initUI(const QString &caption) {
    setFont(subheader_group_box_font);

    auto *main_layout = new QGridLayout(this);

    name_label = new QLabel(caption, this);
    name_label->setFont(default_font);
    name_label->setAlignment(Qt::AlignCenter);

    main_button = new StateButton(QChar(0x2714),
                                  QColor(Qt::green),
                                  "",
                                  QColor(Qt::white),
                                  this);

    main_button->setState(!main_button->getState());

    main_layout->addWidget(name_label, 0, 0);
    main_layout->addWidget(main_button, 1, 0);
}

bool StateButtonWithLabel::getState() {
    return main_button->getState();
}

void StateButtonWithLabel::setState(bool state) {
    main_button->setState(state);
}

void StateButtonWithLabel::setConnections() {
    QObject::connect(main_button, &StateButton::stateChanged,
                     this, &StateButtonWithLabel::stateChanged);
}
