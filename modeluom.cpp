#include "modeluom.h"

modeluom::modeluom(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("Uom");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("UomID");
    index_name = fieldIndex("UomName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Uom Name"));
    selectData();
}

int modeluom::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Uom model ="
             << rowCount();
    return rowCount();
}

QModelIndex modeluom::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modeluom::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modeluom::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modeluom::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modeluom::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modeluom::save() failure: "
                 << lastError().text();
    }
    return result;
}
