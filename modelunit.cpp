#include "modelunit.h"

    modelunit::modelunit(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("Unit");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("UnitID");
    index_name = fieldIndex("UnitName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Unit Name"));
    selectData();
}

int modelunit::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Unit model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelunit::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelunit::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelunit::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelunit::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelunit::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelunit::save() failure: "
                 << lastError().text();
    }
    return result;
}
