#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_INNERSTARTSETTINGSWIDGET_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_INNERSTARTSETTINGSWIDGET_H_

#include <QGroupBox>

#include <widgets/common/basic/statebutton.h>
#include <widgets/common/composed/fullcomposedtimeinput.h>


class InnerStartSettingsWidget: public QGroupBox {
  Q_OBJECT
 public:
  explicit InnerStartSettingsWidget(QWidget *parent = nullptr);

  void setOnButtonState(bool state);
  bool getOnButtonState() const;

  void setInvButtonState(bool state);
  bool getInvButtonState() const;

  void setInnerStartPeriod(const QString &period);
  void setInnerStartPeriod(uint64_t value);
  uint64_t getInnerStartPeriod() const;

  void setInnerStartWidth(const QString &width);
  void setInnerStartWidth(uint64_t value);
  uint64_t getInnerStartWidth() const;

 signals:
  void onStatusChanged(bool status);
  void invStatusChanged(bool status);

  void readPeriodButtonClicked();
  void writePeriodButtonClicked(uint64_t value);
  void readWidthButtonClicked();
  void writeWidthButtonClicked(uint64_t value);

 private:
  FullComposedTimeInput *period_input;
  FullComposedTimeInput *width_input;

  StateButton *on_button;
  StateButton *inv_button;

  void initUI();
  void setConnections();

 private slots:
  void writeButtonClickedProxySlot();

  void onStatusChangedProxySlot();
  void invStatusChangedProxySlot();
};

#endif //SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_INNERSTARTSETTINGSWIDGET_H_
