#include "modelcurrency.h"

modelcurrency::modelcurrency(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("currency");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("CurrencyID");
    index_name = fieldIndex("CurrencyName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Currency Name"));
    selectData();
}

int modelcurrency::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of currency model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelcurrency::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelcurrency::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelcurrency::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelcurrency::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelcurrency::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelcurrency::save() failure: "
                 << lastError().text();
    }
    return result;
}
