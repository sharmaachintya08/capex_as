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

    int capexID = fieldIndex("CapexID");
    int unitID = fieldIndex("UnitID");
    int areaID = fieldIndex("AreaID");
    int categoryID = fieldIndex("CategoryID");
    int subCategoryID = fieldIndex("SubCategoryID");
    int currencyID = fieldIndex("CurrencyID");
    int uomID = fieldIndex("UOMID");
    int recommendedID = fieldIndex("RecommendationID");
    int expTypeID = fieldIndex("ExpTypeID");
    int natureID = fieldIndex("NatureID");
    int frequencyID = fieldIndex("FrequencyID");
    int originID = fieldIndex("OriginID");
    int vendorID = fieldIndex("VendorID");
    int statusID = fieldIndex("StatusID");
    int approverID = fieldIndex("ApproverID");
    int locationID = fieldIndex("LocationID");

    setHeaderData(unitID, Qt::Horizontal, "Unit ID");
    setHeaderData(areaID, Qt::Horizontal, "Area ID");
    setHeaderData(categoryID, Qt::Horizontal, "Category ID");
    setHeaderData(subCategoryID, Qt::Horizontal, "SubCategory ID");
    setHeaderData(currencyID, Qt::Horizontal, "Currency ID");
    setHeaderData(uomID, Qt::Horizontal, "UOM ID");
    setHeaderData(recommendedID, Qt::Horizontal, "Recommendation ID");
    setHeaderData(expTypeID, Qt::Horizontal, "ExpType ID");
    setHeaderData(natureID, Qt::Horizontal, "Nature ID");
    setHeaderData(frequencyID, Qt::Horizontal, "Frequency ID");
    setHeaderData(originID, Qt::Horizontal, "Origin ID");
    setHeaderData(vendorID, Qt::Horizontal, "Vendor ID");
    setHeaderData(statusID, Qt::Horizontal, "Status ID");
    setHeaderData(approverID, Qt::Horizontal, "Approver ID");
    setHeaderData(locationID, Qt::Horizontal, "Location ID");

    setRelation(unitID, QSqlRelation("Unit", "UnitID", "UnitName"));
    setRelation(areaID, QSqlRelation("Area", "AreaID", "AreaName"));
    setRelation(categoryID, QSqlRelation("Category", "CategoryID", "CategoryName"));
    setRelation(subCategoryID, QSqlRelation("subCategory", "subCategoryID", "subCategoryName"));
    setRelation(currencyID, QSqlRelation("Currency", "CurrencyID", "CurrencyName"));
    setRelation(uomID, QSqlRelation("UOM", "UOMID", "UOMName"));
    setRelation(recommendedID, QSqlRelation("RecommendationID", "RecommendationID", "RecommendationName"));
    setRelation(expTypeID, QSqlRelation("ExpType", "ExpTypeID", "ExpTypeName"));
    setRelation(natureID, QSqlRelation("Nature", "NatureID", "NatureName"));
    setRelation(frequencyID, QSqlRelation("Frequency", "FrequencyID", "FrequencyName"));
    setRelation(originID, QSqlRelation("Origin", "OriginID", "OriginName"));
    setRelation(vendorID, QSqlRelation("Vendor", "VendorID", "VendorName"));
    setRelation(statusID, QSqlRelation("Status", "StatusID", "StatusName"));
    setRelation(approverID, QSqlRelation("Approver", "ApproverID", "ApproverName"));
    setRelation(locationID, QSqlRelation("Location", "LocationID", "LocationName"));

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
