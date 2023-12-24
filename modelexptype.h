#ifndef MODELEXPTYPE_H
#define MODELEXPTYPE_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelexptype : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelexptype(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELEXPTYPE_H
