#ifndef CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_CREATIONPART_VIEW_IMPLS_FACTORYVIEWIMPL2_H_
#define CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_CREATIONPART_VIEW_IMPLS_FACTORYVIEWIMPL2_H_

#include <memory>

#include <QTextEdit>

#include <widgets/common/basic/softvalidationspinbox.h>
#include <widgets/common/basic/standardlineedit.h>
#include <widgets/common/basic/standardbutton.h>

#include "deviceplugin/creationpart/view/factoryview.h"


class FactoryViewImpl2: public FactoryView {
 public:
  explicit FactoryViewImpl2(QWidget *parent = nullptr);

  void clearWidget() override;
  QString getValue() override;
  void setValue(const QString &value) override;
  QString getDeviceName() override;
  QString getDeviceDescription() override;
  QString getIP() override;
  int getPort() override;
  int getModbusID() override;
  int getPollPeriod() override;

 private:
  std::shared_ptr<StandardLineEdit> _device_name_line_edit = nullptr;
  // TODO: потом прописать свой текст един в библиотеке widgets и добавить сюда
  std::shared_ptr<QTextEdit> _device_desc_text_edit = nullptr;

  std::shared_ptr<SoftValidationSpinBox> _ip_spinbox = nullptr;
  std::shared_ptr<SoftValidationSpinBox> _port_spinbox = nullptr;
  std::shared_ptr<SoftValidationSpinBox> _modbus_id_spinbox = nullptr;

  std::shared_ptr<StandardButton> _accept_button = nullptr;
  std::shared_ptr<StandardButton> _cancel_button = nullptr;

  void initUI();
  void setConnections();

 private slots:
  void acceptButtonClickedBridgeSlot();
  void cancelButtonClickedBridgeSlot();

};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_CREATIONPART_VIEW_IMPLS_FACTORYVIEWIMPL2_H_
