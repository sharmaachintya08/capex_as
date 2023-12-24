#include "modelvendor.h"

modelvendor::modelvendor(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("vendor");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("vendorID");
    index_name = fieldIndex("vendorName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("vendor Name"));
    selectData();
}

int modelvendor::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of vendor model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelvendor::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelvendor::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelvendor::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelvendor::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelvendor::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelvendor::save() failure: "
                 << lastError().text();
    }
    return result;
}
