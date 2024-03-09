#ifndef OU6UDEVICESTANDALONEPLUGIN_TEST_TABLEMODEL_H_
#define OU6UDEVICESTANDALONEPLUGIN_TEST_TABLEMODEL_H_

#include <memory>

#include <QAbstractTableModel>

#include "abstracttablemodelwrapper.h"
#include "channelmodel.h"

class TableModel: public AbstractTableModelWrapper {
 public:
  explicit TableModel(const std::shared_ptr<ChannelModel> &channel_model,
                      QObject *parent = nullptr);

  int getActualRowsCount() override;
  int rowCount(const QModelIndex &parent) const override;
  int columnCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
  bool insertRows(int row, int count, const QModelIndex &parent) override;
  bool insertColumns(int column, int count, const QModelIndex &parent) override;
  bool removeRows(int row, int count, const QModelIndex &parent) override;

 private:
  std::shared_ptr<ChannelModel> _channel_model = nullptr;

  int _row_count = 0;

  int _rowCount() const;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_TEST_TABLEMODEL_H_
