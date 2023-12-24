#include "modelstatus.h"

modelstatus::modelstatus(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("Status");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("StatusID");
    index_name = fieldIndex("StatusName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Status Name"));
    selectData();
}

int modelstatus::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Status model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelstatus::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelstatus::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelstatus::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelstatus::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelstatus::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelstatus::save() failure: "
                 << lastError().text();
    }
    return result;
}
