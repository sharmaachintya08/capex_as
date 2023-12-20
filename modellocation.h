#ifndef MODELLOCATION_H
#define MODELLOCATION_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class ModelLocation : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit ModelLocation(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELLOCATION_H
