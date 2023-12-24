#ifndef MODELNATURE_H
#define MODELNATURE_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelnature : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelnature(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELNATURE_H
