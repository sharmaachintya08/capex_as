#include "modelcapex.h"

modelcapex::modelcapex(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("Capex");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("CapexID");
    index_name = fieldIndex("CapexName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Capex Name"));
    selectData();
}

int modelcapex::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Capex model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelcapex::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelcapex::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelcapex::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelcapex::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelcapex::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelcapex::save() failure: "
                 << lastError().text();
    }
    return result;
}
