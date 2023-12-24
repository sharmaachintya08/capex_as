#ifndef MODELORIGIN_H
#define MODELORIGIN_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelorigin : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelorigin(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELORIGIN_H
