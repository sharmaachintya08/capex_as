#include "modelsubcategory.h"

modelsubcategory::modelsubcategory(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("Subcategory");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("SubcategoryID");
    index_name = fieldIndex("SubcategoryName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Subcategory Name"));
    selectData();
}

int modelsubcategory::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Subcategory model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelsubcategory::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelsubcategory::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelsubcategory::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelsubcategory::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelsubcategory::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelsubcategory::save() failure: "
                 << lastError().text();
    }
    return result;
}
