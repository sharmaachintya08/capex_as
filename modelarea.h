#ifndef MODELAREA_H
#define MODELAREA_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelarea : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelarea(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELAREA_H
