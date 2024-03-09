#ifndef OU6UDEVICESTANDALONEPLUGIN_TEST_ABSTRACTTABLEMODELWRAPPER_H_
#define OU6UDEVICESTANDALONEPLUGIN_TEST_ABSTRACTTABLEMODELWRAPPER_H_


#include <QAbstractTableModel>


class AbstractTableModelWrapper: public QAbstractTableModel {
 public:
  explicit AbstractTableModelWrapper(QObject *parent = nullptr);

  virtual int getActualRowsCount() = 0;
};

#endif //OU6UDEVICESTANDALONEPLUGIN_TEST_ABSTRACTTABLEMODELWRAPPER_H_
