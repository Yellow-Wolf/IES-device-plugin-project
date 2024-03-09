#ifndef OU6UDEVICESTANDALONEPLUGIN_TEST_CHANNELTABLEVIEW_H_
#define OU6UDEVICESTANDALONEPLUGIN_TEST_CHANNELTABLEVIEW_H_

#include <QTableView>

#include "channelmodel.h"


class ChannelTableView: public QTableView {
  Q_OBJECT
 public:
  explicit ChannelTableView(const std::shared_ptr<ChannelModel> &channel_model, QWidget *parent = nullptr);

 private:
  std::shared_ptr<ChannelModel> _channel_model = nullptr;

  void initUI();
  void setConnections();

 private slots:
  void channelDoubleClickedBridgeSlot(const QModelIndex &index);
};

#endif //OU6UDEVICESTANDALONEPLUGIN_TEST_CHANNELTABLEVIEW_H_
