#include "qtmodelnotifier.h"

#include <QDebug>


QtModelNotifier::QtModelNotifier(const std::shared_ptr<AbstractTableModelWrapper> &table_model):
  _table_model(table_model) {

}

void QtModelNotifier::insertRows(int row, int count) {
  if (_table_model != nullptr) {
    int row_diff = getRowDiff();
    if (row_diff > 0) {
      _table_model->insertRows(row, row_diff, {});
    }
  }
}

void QtModelNotifier::removeRows(int row, int count) {
  if (_table_model != nullptr) {
    int row_diff = getRowDiff();
    if (row_diff < 0) {
      _table_model->removeRows(row, -row_diff, {});
    }
  }
}

void QtModelNotifier::insertColumns(int column, int count) {

}

void QtModelNotifier::removeColumns(int column, int count) {

}


int QtModelNotifier::getRowDiff() {
  int result = 0;

  if (_table_model != nullptr) {
    auto row_count = _table_model->rowCount({});
    auto actual_row_count = _table_model->getActualRowsCount();

    result = row_count - actual_row_count;
  } else {
    qCritical() << "table model is nullptr for notifier " << __func__;
  }

  return result;
}
