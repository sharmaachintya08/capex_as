#ifndef MODELFREQUENCY_H
#define MODELFREQUENCY_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelfrequency : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelfrequency(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};
#endif // MODELFREQUENCY_H
