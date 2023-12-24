#ifndef MODELSUBCATEGORY_H
#define MODELSUBCATEGORY_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelsubcategory : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelsubcategory(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};
#endif // MODELSUBCATEGORY_H
