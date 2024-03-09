#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_DOWNPORTWIDGET_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_DOWNPORTWIDGET_H_

#include <QGroupBox>

#include <widgets/common/basic/standardpropertylabel.h>
#include <widgets/common/basic/ledwidget.h>
#include <widgets/common/basic/standardbutton.h>


class RFModuleWidget: public QGroupBox {
  Q_OBJECT
 public:
  explicit RFModuleWidget(QWidget *parent = nullptr);

  void setRxLossStatus(bool enabled);
  void setTxFaultStatus(bool status);
  void setRxLoss(bool status);
  void setTxFault(bool status);

 signals:
  void rxClicked();
  void txClicked();

  void getSFPParams();

 private:
  // WIDGET POINTERS
  EditableLedWidget *rx_led_widget;
  EditableLedWidget *tx_led_widget;
  LedWidget *rx_loss_led_widget;
  LedWidget *tx_fault_led_widget;

  void initUI();
};

#endif //SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_DOWNPORTWIDGET_H_