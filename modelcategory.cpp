#include "modelcategory.h"

modelcategory::modelcategory(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("category");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("CategoryID");
    index_name = fieldIndex("CategoryName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Category Name"));
    selectData();
}

int modelcategory::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of category model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelcategory::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelcategory::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelcategory::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelcategory::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelcategory::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelcategory::save() failure: "
                 << lastError().text();
    }
    return result;
}
