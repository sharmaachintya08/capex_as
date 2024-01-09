#ifndef MODELCAPEX_H
#define MODELCAPEX_H


#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QMessageBox>
#include <QSqlError>

class modelcapex : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    explicit modelcapex(QObject *parent = nullptr);

    int index_id;
    int index_name;

    int selectData();
    QModelIndex create(const int &row);
    bool save();
};

#endif // MODELCAPEX_H
