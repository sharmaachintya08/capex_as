#include "modellocation.h"

ModelLocation::ModelLocation(QObject *parent)
    : QSqlRelationalTableModel{parent}
{
    setTable("Location");
    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("LocationID");
    index_name = fieldIndex("LocationName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Location Name"));
    selectData();
}

int ModelLocation::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Approver Model = " << rowCount();
    return rowCount();
}

QModelIndex ModelLocation::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if (insertRecord(row, sqlRecord))
    {
        modelIndex = index(row, 0);
        qDebug() << "DEBUG: ApproverModel::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: ApproverModel::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool ModelLocation::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result){
        database().commit();
        qDebug() << "DEBUG: ApproverModel::save() success.";
    } else {
        database().rollback();
        qDebug() << "DEBUG: ApproverModel::save() failure: "
                 << lastError().text();
        // TODO: Warning message and log
    }
    return result;
}
