#include "tablemodel.h"

#include <QDebug>

static const QVector<QString> HEADERS_DATA = {
    "Num", "Name", "Delay", "Width", "Enabled", "Inverted"
};


TableModel::TableModel(const std::shared_ptr<ChannelModel> &channel_model, QObject *parent):
    AbstractTableModelWrapper(parent), _channel_model(channel_model) {
  _row_count = _rowCount();
}

int TableModel::_rowCount() const {
  int result = 0;

  if (_channel_model != nullptr) {
    result = _channel_model->getChannelCount();
  }

  qDebug() << result << " is row count " << __func__;
  return result;
}

int TableModel::rowCount(const QModelIndex &parent) const {
  int result = _rowCount();
  return result;
}

int TableModel::columnCount(const QModelIndex &parent) const {
  return HEADERS_DATA.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) return {};

  if (role == Qt::DisplayRole) {
    auto row = index.row();
    auto column = index.column();

    if (_channel_model != nullptr) {
      auto dto = _channel_model->getChannelData(row);

      switch (column) {
        case 0:
          return row;
        case 1:
          return QString::fromStdString(dto.channel_name);
        case 2:
          return dto.channel_delay;
        case 3:
          return dto.channel_width;
        case 4:
          return dto.channel_enabled;
        case 5:
          return dto.channel_inverted;
      }
    }
  }

  return {};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
    if (section >= 0 && section < HEADERS_DATA.size()) {
      return HEADERS_DATA[section];
    }
  }

  return QAbstractItemModel::headerData(section, orientation, role);
}

bool TableModel::insertRows(int row, int count, const QModelIndex &parent) {
  beginInsertRows(parent, row, row + count - 1);
  _row_count += count;
  endInsertRows();
  return QAbstractItemModel::insertRows(row, count, parent);
}

bool TableModel::removeRows(int row, int count, const QModelIndex &parent) {
  beginRemoveRows(parent, row, row + count - 1);
  _row_count -= count;
  endRemoveRows();
  return QAbstractItemModel::removeRows(row, count, parent);
}

bool TableModel::insertColumns(int column, int count, const QModelIndex &parent) {
  return QAbstractItemModel::insertColumns(column, count, parent);
}


int TableModel::getActualRowsCount() {
  return _row_count;
}
