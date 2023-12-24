#ifndef MODELUNIT_H
#define MODELUNIT_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelunit : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelunit(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};



#endif // MODELUNIT_H
