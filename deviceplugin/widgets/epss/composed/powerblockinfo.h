#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_POWERBLOCKINFO_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_POWERBLOCKINFO_H_

#include <QGroupBox>

#include <widgets/common/basic/lampwidget.h>

#include "deviceplugin/enums.h"


class PowerBlockInfo : public QGroupBox {
  Q_OBJECT
 public:
  explicit PowerBlockInfo(QWidget *parent);

  void setRfJoinState(LampStates state);
  LampStates getRfJoinState() const;
  void setSyncJoinState(LampStates state);
  LampStates getSyncJoinState() const;
  void setRfInState(LampStates state);
  LampStates getRfInState() const;
  void setSyncInState(LampStates state);
  LampStates getSyncInState() const;
  void setRfOutState(LampStates state);
  LampStates getRfOutState() const;
  void setSyncOutState(LampStates state);
  LampStates getSyncOutState() const;

 private:
  LampWidget *rf_join_lamp;
  LampWidget *sync_join_lamp;
  LampWidget *rf_in_lamp;
  LampWidget *sync_in_lamp;
  LampWidget *rf_out_lamp;
  LampWidget *sync_out_lamp;

  void initUI();
};

#endif //SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_POWERBLOCKINFO_H_
