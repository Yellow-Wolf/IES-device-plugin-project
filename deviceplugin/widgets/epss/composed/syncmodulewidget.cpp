#include "syncmodulewidget.h"

#include <QVBoxLayout>


SyncModuleWidget::SyncModuleWidget(const QString &sfp_module_name, QWidget *parent):
  QGroupBox(sfp_module_name, parent) {
  initUI();
}

void SyncModuleWidget::setDesLockStatus(bool status) {
  des_lock_led_widget->setState(status);
}

void SyncModuleWidget::setOscLockStatus(bool status) {
  osc_lock_led_widget->setState(status);
}

void SyncModuleWidget::setRxLossStatus(bool status) {
  rx_loss_led_widget->setState(status);
}

void SyncModuleWidget::setTxFaultStatus(bool status) {
  tx_fault_led_widget->setState(status);
}


void SyncModuleWidget::initUI() {
  setFont(QFont("Segoe UI", 16));

  auto *main_layout = new QVBoxLayout(this);
  auto *led_form_layout = new QGridLayout;

  auto *des_lock_label = new StandardPropertyLabel("des lock: ", 14, this);
  auto *osc_lock_label = new StandardPropertyLabel("osc lock: ", 14, this);
  auto *rx_loss_label = new StandardPropertyLabel("rx loss: ", 14, this);
  auto *tx_fault_label = new StandardPropertyLabel("tx fault: ", 14, this);

  des_lock_led_widget = new LedWidget(Qt::green, Qt::gray, this);
  osc_lock_led_widget = new LedWidget(Qt::green, Qt::gray, this);
  rx_loss_led_widget = new LedWidget(Qt::gray, Qt::red, this);
  tx_fault_led_widget = new LedWidget(Qt::gray, Qt::red, this);

  auto *get_sfp_params_button = new StandardButton(tr("SFP parameters"), this);

  led_form_layout->addWidget(des_lock_label, 0, 0);
  led_form_layout->addWidget(osc_lock_label, 1, 0);
  led_form_layout->addWidget(rx_loss_label, 2, 0);
  led_form_layout->addWidget(tx_fault_label, 3, 0);

  led_form_layout->addWidget(des_lock_led_widget, 0, 1, Qt::AlignRight);
  led_form_layout->addWidget(osc_lock_led_widget, 1, 1, Qt::AlignRight);
  led_form_layout->addWidget(rx_loss_led_widget, 2, 1, Qt::AlignRight);
  led_form_layout->addWidget(tx_fault_led_widget, 3, 1, Qt::AlignRight);

  main_layout->addLayout(led_form_layout);
  main_layout->addWidget(get_sfp_params_button);

  // CONNECTIONS

  QObject::connect(get_sfp_params_button, &StandardButton::released,
                   this, &SyncModuleWidget::getSFPParamsSignal);
}

