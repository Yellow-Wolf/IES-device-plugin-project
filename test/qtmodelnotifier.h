#ifndef MAESTRO_SOFTWARE_MODELS_QT_QTMODELNOTIFIER_H_
#define MAESTRO_SOFTWARE_MODELS_QT_QTMODELNOTIFIER_H_

#include <memory>

#include <QAbstractTableModel>
#include <utils/storages/dimchangenotifier.h>
#include "abstracttablemodelwrapper.h"

class QtModelNotifier: public DimChangeNotifier {
 public:
  explicit QtModelNotifier(const std::shared_ptr<AbstractTableModelWrapper> &table_model);

  void insertRows(int row, int count) override;
  void removeRows(int row, int count) override;
  void insertColumns(int column, int count) override;
  void removeColumns(int column, int count) override;

 private:
  std::shared_ptr<AbstractTableModelWrapper> _table_model = nullptr;

  int getRowDiff();
};

#endif //MAESTRO_SOFTWARE_MODELS_QT_QTMODELNOTIFIER_H_
