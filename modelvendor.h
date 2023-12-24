#ifndef MODELVENDOR_H
#define MODELVENDOR_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelvendor : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelvendor(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELVENDOR_H
