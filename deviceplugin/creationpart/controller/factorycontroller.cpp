#include "factorycontroller.h"

#include <QDebug>


FactoryController::FactoryController(const std::shared_ptr<FactoryView> &factory_view,
                                     const std::shared_ptr<FactoryUseCase> &factory_usecase):
                                     _factory_view(factory_view),
                                     _factory_usecase(factory_usecase) {
  setConnections();
}

void FactoryController::setConnections() {
  if (_factory_view != nullptr) {
    QObject::connect(_factory_view.get(), &FactoryView::valueChanged,
                     this, &FactoryController::viewFactoryValueChanged);

    QObject::connect(_factory_view.get(), &FactoryView::createActionSignal,
                     this, &FactoryController::createActionViewSlot);
  }

  if (_factory_usecase != nullptr) {
    QObject::connect(_factory_usecase.get(), &FactoryUseCase::testValueChanged,
                     this, &FactoryController::factoryUseCaseValueChanged);
  }
}

void FactoryController::factoryUseCaseValueChanged(const QString &s) {
  if (_factory_view != nullptr) {
    _factory_view->setValue(s);
  }
}

void FactoryController::viewFactoryValueChanged(const QString &s) {
  if (_factory_usecase != nullptr) {
    qDebug() << s;
  }
}

void FactoryController::createActionViewSlot(const QString &device_name, const QString &device_desc,
                                             const QString &ip, int port, int modbus_id,
                                             int poll_period) {
  if (_factory_usecase != nullptr) {

    FactoryUseCaseRequest request = {
        device_name.toStdString(),
        device_desc.toStdString(),
        ip.toStdString(),
        port,
        modbus_id,
        poll_period
    };

    auto response = _factory_usecase->execute(request);

    // TODO: ПРОДОЛЖИТЬ ЗДЕСЬ!

    response.device_view->show();

    auto &plugin_provider = response.plugin_provider;
    if (plugin_provider != nullptr) {
      auto connection_widget = plugin_provider->getConnectionWidget();
      if (connection_widget != nullptr) {
        connection_widget->show();
      }
    }
  }
}
