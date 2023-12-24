#ifndef MODELUOM_H
#define MODELUOM_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

    class modeluom : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modeluom(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELUOM_H
