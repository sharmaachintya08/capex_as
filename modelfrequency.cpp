#include "modelfrequency.h"

modelfrequency::modelfrequency(QObject *parent)
    :QSqlRelationalTableModel{parent}
{
    setTable("Frequency");

    setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    index_id = fieldIndex("FrequencyID");
    index_name = fieldIndex("FrequencyNAME");

    setHeaderData(index_id, Qt::Horizontal, tr("ID"));
    setHeaderData(index_name, Qt::Horizontal, tr("Frequency Name"));
    selectData();
}

int modelfrequency::selectData()
{
    select();
    qDebug() << "DEBUG: rowCount of frequency model ="
             << rowCount();
    return rowCount();
}

QModelIndex modelfrequency::create(const int &row)
{
    QModelIndex modelIndex = QModelIndex();
    QSqlRecord sqlRecord = record();

    if(insertRecord(row, sqlRecord))
    {
        modelIndex = index(row,0);
        qDebug() << "DEBUG: modelfrequency::createAction() insertRecord index: "
                 << modelIndex;
    }
    qDebug() << "DEBUG: modelfrequency::createAction() index returned: "
             << modelIndex;
    return modelIndex;
}

bool modelfrequency::save()
{
    bool result = false;

    database().transaction();
    result = submitAll();
    if(result)
    {
        database().commit();
        qDebug() << "DEBUG: modelfrequency::save() success";
    }
    else
    {
        database().rollback();
        qDebug() << "DEBUG: modelfrequency::save() failure: "
                 << lastError().text();
    }
    return result;
}
