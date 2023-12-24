#include "modelexptype.h"

modelexptype::modelexptype(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("exptype");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("ExptypeID");
    index_name = fieldIndex("ExptypeName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Exptype Name"));
    selectData();
}

int modelexptype::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of exptype model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelexptype::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelexptype::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelexptype::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelexptype::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelexptype::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelexptype::save() failure: "
                 << lastError().text();
    }
    return result;
}
