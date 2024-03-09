#ifndef SYNC_SYS_DEVICE_WIDGET_CHANNELSBOXV2_H
#define SYNC_SYS_DEVICE_WIDGET_CHANNELSBOXV2_H

#include "channelscountstrategy.h"
#include "deviceplugin/widgets/epss/basic/channelbutton.h"

#include <vector>
#include <string>

#include <QGroupBox>

class ChannelsCountStrategy;


class ChannelsBoxV2 : public QGroupBox {
Q_OBJECT
public:
  /*!
   *
   * @param label_text название группы кнопок каналов;
   * @param parent виджет, на котором располагается этот виджет.
   */
  explicit ChannelsBoxV2(ChannelsCountStrategy *channels_count_strategy, QWidget *parent = nullptr);

  /*!
   * Функция сообщает, есть ли в группе выбранная кнопка.
   * @return
   * 0 - нет;
   * 1 - есть.
   */
    bool hasChosenButton() const;
    int getChannelsCount() const;
    int getCurrentChannelNum() const;

    void selectChannel(int channel_num);
    void unChoseButtons();

    bool getOnButtonState(int button_num) const;
    void setOnButtonState(int button_num, bool enabled);

    bool getInvButtonState(int button_num) const;
    void setInvButtonState(int button_num, bool inverted);

signals:
    void channelChosenActionSignal(int button_num);

protected:
    std::vector<ChannelButton*> buttons;

protected slots:
    virtual void buttonClickedSlot(bool e);

private:
    int current_channel_num;

    void initUI(ChannelsCountStrategy *channels_count_strategy);
    void setConnections();
};

#endif //SYNC_SYS_DEVICE_WIDGET_CHANNELSBOXV2_H
