#include "modelarea.h"

modelarea::modelarea(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("area");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("AreaID");
    index_name = fieldIndex("AreaName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Area Name"));
    selectData();
}

int modelarea::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of area model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelarea::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: areamodel::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: areamodel::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelarea::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: areamodel::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: areamodel::save() failure: "
                 << lastError().text();
    }
    return result;
}
