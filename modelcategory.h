#ifndef MODELCATEGORY_H
#define MODELCATEGORY_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelcategory : public QSqlRelationalTableModel
{
    Q_OBJECT;
public:
    explicit modelcategory(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELCATEGORY_H
