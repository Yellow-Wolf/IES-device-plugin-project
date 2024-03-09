#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_CONTROLLER_FACTORYCONTROLLER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_CONTROLLER_FACTORYCONTROLLER_H_

#include <memory>
#include <QObject>

#include "deviceplugin/creationpart/view/factoryview.h"
#include "deviceplugin/creationpart/usecase/factoryusecase.h"


class FactoryController: public QObject {
  Q_OBJECT
 public:
  explicit FactoryController(const std::shared_ptr<FactoryView> &factory_view,
                             const std::shared_ptr<FactoryUseCase> &factory_usecase);

 private:
  std::shared_ptr<FactoryView> _factory_view = nullptr;
  std::shared_ptr<FactoryUseCase> _factory_usecase = nullptr;


  void setConnections();

 private slots:
  void factoryUseCaseValueChanged(const QString &s);
  void viewFactoryValueChanged(const QString &s);

  void createActionViewSlot(const QString &name, const QString &desc, const QString &ip, int port, int modbus_id, int poll_period);
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_CREATIONPART_CONTROLLER_FACTORYCONTROLLER_H_
