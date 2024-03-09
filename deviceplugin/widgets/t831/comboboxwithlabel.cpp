#include <QGridLayout>
#include "comboboxwithlabel.h"
#include "deviceplugin/consts.h"


ComboBoxWithLabel::ComboBoxWithLabel(const QString &caption, const QMap<int, QString> &states, QWidget *parent) : QWidget(parent){
    initUI(caption, states);
    setConnections();
}

int ComboBoxWithLabel::getState() {
    return main_combobox->getState();
}

void ComboBoxWithLabel::setState(int16_t state) {
    main_combobox->setState((int)state);
}

void ComboBoxWithLabel::updateStates(const QMap<int, QString> &states, int current_state) {
    main_combobox->updateStates(states, current_state);
}

void ComboBoxWithLabel::initUI(const QString &caption, const QMap<int, QString> &states) {
    setFont(subheader_group_box_font);

    auto *main_layout = new QGridLayout(this);

    name_label = new QLabel(caption, this);
    name_label->setFont(default_font);
    name_label->setAlignment(Qt::AlignCenter);

    main_combobox = new StandardUShortCombobox(states, this);

    main_layout->addWidget(name_label, 0, 0);
    main_layout->addWidget(main_combobox, 1, 0);
}

void ComboBoxWithLabel::setConnections() {
    QObject::connect(main_combobox, &StandardUShortCombobox::stateChanged,
                     this, &ComboBoxWithLabel::stateChanged);
}

ComboBoxWithLabel::ComboBoxWithLabel(QWidget *parent) : QWidget(parent){

}
