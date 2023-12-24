#ifndef MODELCURRENCY_H
#define MODELCURRENCY_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelcurrency : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelcurrency(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELCURRENCY_H
