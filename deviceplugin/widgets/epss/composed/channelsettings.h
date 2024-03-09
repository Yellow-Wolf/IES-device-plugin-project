#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_CHANNELSETTINGS_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_CHANNELSETTINGS_H_

#include <QGroupBox>
#include <QPushButton>

#include <widgets/common/basic/timeinputspinbox.h>

#include "deviceplugin/enums.h"


class ChannelSettings : public QGroupBox {
  Q_OBJECT
 public:
  explicit ChannelSettings(QWidget *parent = nullptr);
  void setDelay(const QString &delay);
  bool getDelay(double time, Units unit);
  void setWidth(const QString &width);
  bool getWidth(double time, Units unit);

 signals:
  void invertButtonClicked();
  void onOffButtonClicked();
  void saveChangesButtonClicked(uint64_t delay, uint64_t width);

 private:
  const QString block_name = QString("Настройки канала");
  TimeInputSpinBox *delay_input_spin_box;
  TimeInputSpinBox *width_input_spin_box;

  QPushButton *on_off_button;
  QPushButton *invert_button;
  QPushButton *save_changes_button;

  void initUI();
  void setConnections();

 private slots:
  void checkSaveChangesButtonEnabled();
  void packDelayWidthValues();
};

#endif // SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_CHANNELSETTINGS_H_
