#include "modelorigin.h"

modelorigin::modelorigin(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("origin");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("OriginID");
    index_name = fieldIndex("OriginName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Origin Name"));
    selectData();
}

int modelorigin::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Nature model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelorigin::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelorigin::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelorigin::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelorigin::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelorigin::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelorigin::save() failure: "
                 << lastError().text();
    }
    return result;
}
