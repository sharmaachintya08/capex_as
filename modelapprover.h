#ifndef MODELAPPROVER_H
#define MODELAPPROVER_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class ModelApprover : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit ModelApprover(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELAPPROVER_H
