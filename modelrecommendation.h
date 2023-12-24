#ifndef MODELRECOMMENDATION_H
#define MODELRECOMMENDATION_H

#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelrecommendation : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelrecommendation(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELRECOMMENDATION_H
