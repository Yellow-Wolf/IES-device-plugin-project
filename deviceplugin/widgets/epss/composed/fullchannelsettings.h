#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_FULLCHANNELSETTINGS_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_FULLCHANNELSETTINGS_H_

#include <QGroupBox>
#include <QRadioButton>

#include <widgets/common/composed/fullcomposedlineedit.h>
#include <widgets/common/composed/fullcomposedtimeinput.h>
#include <widgets/common/basic/standardcombobox.h>
#include <widgets/common/basic/standardpropertylabel.h>
#include <widgets/common/basic/statebutton.h>
#include "deviceplugin/managementpart/components/mainmanagement/views/deviceviewdata.h"

class FullChannelSettings: public QGroupBox {
  Q_OBJECT
 public:
  explicit FullChannelSettings(const QMap<int, QString>& start_names, bool sk1,
                               QWidget *parent = nullptr);

  void setCurrentChannelNum(const QString &channel_const_name, const QString &channel_name);
  void setChannelName(const QString &text);
  QString getChannelName();

  int getStartSource();
  void setStartSource(int des_num);

  void setFromStartMode();
  void setProxyMode();

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

  void updateChannelSettings(const ChannelViewData &data);

 signals:
  void getChannelNameActionSignal();
  void channelNameChangedSignal(const QString &name);

  void startSourceChangedSignal(int source);
  void fromStartSelectedSignal();
  void proxyStartSelectedSignal();

  void onStatusChanged(bool status);
  void invStatusChanged(bool status);

  void readDelayButtonClicked();
  void writeDelayButtonClicked(uint64_t value);
  void readWidthButtonClicked();
  void writeWidthButtonClicked(uint64_t value);

 private:
  FullComposedLineEdit *name_input_ledit = nullptr;

  FullComposedTimeInput *delay_input = nullptr;
  FullComposedTimeInput *width_input = nullptr;
  FullComposedTimeInput *delay_module_input = nullptr;

  StateButton *on_button = nullptr;
  StateButton *inv_button = nullptr;

  StandardUShortCombobox *start_des_combobox = nullptr;

  QRadioButton *proxy_start_radio_button = nullptr;
  QRadioButton *from_start_radio_button = nullptr;
  QRadioButton *freq_radio_button = nullptr;

  QGroupBox *from_start_group_box = nullptr;

  void initUI(const QMap<int, QString>& start_names, bool ck1);
  void setConnections();

 private slots:
  void writeButtonClickedProxySlot();

  void onStatusChangedProxySlot();
  void invStatusChangedProxySlot();
};

#endif //SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_COMPOSED_FULLCHANNELSETTINGS_H_
