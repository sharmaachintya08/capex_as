#ifndef MODELSTATUS_H
#define MODELSTATUS_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelstatus : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelstatus(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};



#endif // MODELSTATUS_H
