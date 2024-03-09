#ifndef SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_BASIC_CHANNELBUTTON_H_
#define SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_BASIC_CHANNELBUTTON_H_

#include "deviceplugin/enums.h"

#include <QPushButton>


/*!
 * Класс представляет из себя кнопку, у которой есть 3 состояния: выключена, включена и выбрана.
 * Каждое состояние обладает собственным цветом. И может быть инвертировано.
 */
class ChannelButton : public QPushButton{
  Q_OBJECT
 public:
  explicit ChannelButton(const QString &button_name, QWidget *parent = nullptr);
  /*!
   * Функция включает/выключает кнопку.
   * @param switch_ -
   * true - включена;\n
   * false - выключена.
   */
  void setOn(bool switched);
  bool isOn() const;

  /*!
   * Метод инвертирует кнопку.
   * @param invert true - инвертирована;\n
   * false - не инвертирована.
   */
  void setInvert(bool inverted);
  bool isInverted() const;

  /*!
   * Метод устанавливает состояние кнопки.
   * @param chose true - включена\n
   * false - выключена.
   */
  void setChosen(bool chosen);
  bool isChosen() const;

 private:
  /*!
   * Состояние кнопки:
   * 0 - выключена (серый);
   * 1 - включена (синий).
   */
  bool switched = false;
  /*!
   * Состояние кнопки:
   * 0 - не инвертирована;
   * 1 - инвертирована.
   */
  bool inverted = false;
  /*!
   * Состояние кнопки: 0 - не выбрана; 1 - выбрана.
   */
  bool chosen = false;


  void initUI(const QString &button_name);
  void changeStyleSheet();
};

#endif //SYNCSYS_DEVICE_WIDGET_WIDGETS_EPSS_BASIC_CHANNELBUTTON_H_
