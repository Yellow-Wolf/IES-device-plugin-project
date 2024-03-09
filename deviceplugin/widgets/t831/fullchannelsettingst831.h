#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_FULLCHANNELSETTINGST831_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_FULLCHANNELSETTINGST831_H_

#include <QGroupBox>
#include <QRadioButton>

#include <widgets/common/composed/fullcomposedlineedit.h>
#include <widgets/common/composed/fullcomposedtimeinput.h>
#include <widgets/common/basic/standardcombobox.h>
#include <widgets/common/basic/standardpropertylabel.h>
#include <widgets/common/basic/statebutton.h>

class FullChannelSettingsT831: public QGroupBox {
  Q_OBJECT
 public:
  explicit FullChannelSettingsT831(QWidget *parent = nullptr);

  void setCurrentChannelNum(const QString &channel_const_name, const QString &channel_name);
  void setChannelName(const QString &text);
  QString getChannelName();

  void setOnButtonState(bool state);
  bool getOnButtonState() const;

  void setInvButtonState(bool state);
  bool getInvButtonState() const;

  void setChannelDelay(const QString &delay);
  void setChannelDelay(uint64_t value);
  uint64_t getChannelDelayValue() const;

  void setChannelWidth(const QString &width);
  void setChannelWidth(uint64_t value);
  uint64_t getChannelWidthValue() const;

 signals:
  void getChannelNameActionSignal();

  void channelNameChangedSignal(const QString &name);

  void onStatusChanged(bool status);
  void invStatusChanged(bool status);

  void readDelayButtonClicked();
  void writeDelayButtonClicked(uint64_t value);
  void readWidthButtonClicked();
  void writeWidthButtonClicked(uint64_t value);

 private:
  FullComposedLineEdit *name_input_ledit;

  FullComposedTimeInput *delay_input;
  FullComposedTimeInput *width_input;

  StateButton *on_button;
  StateButton *inv_button;

  QGroupBox *from_start_group_box;

  void initUI();
  void setConnections();

 private slots:
  void writeButtonClickedProxySlot();

  void onStatusChangedProxySlot();
  void invStatusChangedProxySlot();
};

#endif //SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_FULLCHANNELSETTINGS_H_
