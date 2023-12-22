#include "modelapprover.h"

ModelApprover::ModelApprover(QObject *parent)
    : QSqlRelationalTableModel{parent}
{
    setTable("Approver");
    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("ApproverID");
    index_name = fieldIndex("ApproverName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Approver Name"));
    selectData();
}

int ModelApprover::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Approver Model =" << rowCount();
    return rowCount();
}

QModelIndex ModelApprover::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if (insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: ApproverModel::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: ApproverModel::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool ModelApprover::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: ApproverModel::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: ApproverModel::save() failure: "
                 << lastError().text();
    }

    return result;
}
