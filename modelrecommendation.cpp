#include "modelrecommendation.h"

modelrecommendation::modelrecommendation(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("Recommendation");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("RecommendationID");
    index_name = fieldIndex("RecommendationName");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Recommendation Name"));
    selectData();
}

int modelrecommendation::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of Recommendation model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelrecommendation::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelrecommendation::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelrecommendation::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelrecommendation::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelrecommendation::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelrecommendation::save() failure: "
                 << lastError().text();
    }
    return result;
}
