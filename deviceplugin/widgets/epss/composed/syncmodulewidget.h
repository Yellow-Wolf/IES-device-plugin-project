#ifndef SYNC_SYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_SYNCMODULEWIDGET_H_
#define SYNC_SYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_SYNCMODULEWIDGET_H_

#include <QGroupBox>

#include <widgets/common/basic/standardpropertylabel.h>
#include <widgets/common/basic/ledwidget.h>
#include <widgets/common/basic/standardbutton.h>


class SyncModuleWidget: public QGroupBox {
  Q_OBJECT
 public:
  explicit SyncModuleWidget(const QString &sfp_module_name = "SYNC", QWidget *parent = nullptr);

  void setDesLockStatus(bool status);
  void setOscLockStatus(bool status);
  void setRxLossStatus(bool status);
  void setTxFaultStatus(bool status);

 signals:
  void getSFPParamsSignal();



 private:
  // WIDGET POINTERS
  LedWidget *des_lock_led_widget;
  LedWidget *osc_lock_led_widget;
  LedWidget *rx_loss_led_widget;
  LedWidget *tx_fault_led_widget;

  void initUI();
};

#endif // SYNC_SYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_SYNCMODULEWIDGET_H_
