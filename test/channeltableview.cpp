#include "channeltableview.h"

#include <QDebug>


ChannelTableView::ChannelTableView(const std::shared_ptr<ChannelModel> &channel_model,
                                   QWidget *parent) :
                                   QTableView(parent),
                                   _channel_model(channel_model) {
  initUI();
  setConnections();
}

void ChannelTableView::initUI() {

}

void ChannelTableView::setConnections() {
  QObject::connect(this, &QTableView::doubleClicked,
                   this, &ChannelTableView::channelDoubleClickedBridgeSlot);
}

void ChannelTableView::channelDoubleClickedBridgeSlot(const QModelIndex &index) {
  auto row = index.row();

  if (_channel_model != nullptr) {
    auto data = _channel_model->getPluginProviderByChannelNum(row);
    auto plugin_provider = data.first;
    auto channel_num = data.second;

    if (plugin_provider != nullptr) {
      auto channel_edit_widget = plugin_provider->getManagementWidget("EditChannel", channel_num);

      if (channel_edit_widget != nullptr) {
        channel_edit_widget->show();
      }
    }

  } else {
    qCritical() << "_channel_model is nullptr " << __func__;
  }
}
