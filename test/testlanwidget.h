#ifndef OU6UDEVICESTANDALONEPLUGIN_TEST_TESTLANWIDGET_H_
#define OU6UDEVICESTANDALONEPLUGIN_TEST_TESTLANWIDGET_H_

#include <memory>

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include <plugin/storages/pluginproviderstorage.h>


class TestLanWidget: public QWidget {
  Q_OBJECT
 public:
  explicit TestLanWidget(const std::shared_ptr<PluginProviderStorage> &plugin_provider_storage,
                         QWidget *parent = nullptr):
      QWidget(),
      _plugin_provider_storage(plugin_provider_storage) {
    initUI();
  }

  void initUI() {
    auto main_layout = new QVBoxLayout(this);

    auto connect_button = new QPushButton("Connect");

    QObject::connect(connect_button, &QAbstractButton::released,
                     this, &TestLanWidget::connectButtonClicked);

    main_layout->addWidget(connect_button);
  }

 private:
  std::shared_ptr<PluginProviderStorage> _plugin_provider_storage = nullptr;

 private slots:
  void connectButtonClicked() {
    if (_plugin_provider_storage != nullptr) {
      auto all_devices = _plugin_provider_storage->getAllDevices();
      for (auto &device: all_devices) {
        auto plugin_provider = device.second;
        if (plugin_provider != nullptr) {
          plugin_provider->connectHW(true);
        }
      }
    }
  }
};


#endif //OU6UDEVICESTANDALONEPLUGIN_TEST_TESTLANWIDGET_H_
