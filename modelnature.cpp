#include "modelnature.h"

modelnature::modelnature(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("nature");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("NatureID");
    index_name = fieldIndex("NatureName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Nature Name"));
    selectData();
}

int modelnature::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Nature model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelnature::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelnature::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelnature::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelnature::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelnature::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelnature::save() failure: "
                 << lastError().text();
    }
    return result;
}
