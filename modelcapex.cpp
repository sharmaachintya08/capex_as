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
    int BudgetNo = fieldIndex("BudgetNo");
    int UnitID = fieldIndex("UnitID");
    int LocationID = fieldIndex("LocationID");
    int AreaID = fieldIndex("AreaID");
    int CategoryID = fieldIndex("CategoryID");
    int SubCategoryID = fieldIndex("SubcategoryID");
    int CurrencyID = fieldIndex("CurrencyID");
    int UOMID = fieldIndex("UOMID");
    int RecommendationID = fieldIndex("RecommendationID");
    int ExpTypeID = fieldIndex("ExpTypeID");
    int NatureID = fieldIndex("NatureID");
    int FrequencyID = fieldIndex("FrequencyID");
    int OriginID = fieldIndex("OriginID");
    int VendorID = fieldIndex("VendorID");
    int StatusID = fieldIndex("StatusID");
    int ApproverID = fieldIndex("ApproverID");

    setHeaderData(capexID, Qt::Horizontal, "Capex ID");
    setHeaderData(BudgetNo, Qt::Horizontal, "Reference No");
    setHeaderData(UnitID, Qt::Horizontal, "Unit");
    setHeaderData(LocationID, Qt::Horizontal, "Location");
    setHeaderData(AreaID, Qt::Horizontal, "Area");
    setHeaderData(CategoryID, Qt::Horizontal, "Category");
    setHeaderData(SubCategoryID, Qt::Horizontal, "Subcategory");
    setHeaderData(CurrencyID, Qt::Horizontal, "Currency");
    setHeaderData(UOMID, Qt::Horizontal, "UOM");
    setHeaderData(RecommendationID, Qt::Horizontal, "Recommendation");
    setHeaderData(ExpTypeID, Qt::Horizontal, "ExpType");
    setHeaderData(NatureID, Qt::Horizontal, "Nature");
    setHeaderData(FrequencyID, Qt::Horizontal, "Frequency");
    setHeaderData(OriginID, Qt::Horizontal, "Origin");
    setHeaderData(VendorID, Qt::Horizontal, "Vendor");
    setHeaderData(StatusID, Qt::Horizontal, "Status");
    setHeaderData(ApproverID, Qt::Horizontal, "Approver");

    setRelation(UnitID, QSqlRelation("Unit", "UnitID", "UnitName"));
    setRelation(LocationID, QSqlRelation("Location", "LocationID", "LocationName"));
    setRelation(AreaID, QSqlRelation("Area", "AreaID", "AreaName"));
    setRelation(CategoryID, QSqlRelation("Category", "CategoryID", "CategoryName"));
    setRelation(SubCategoryID, QSqlRelation("Subcategory", "SubcategoryID", "SubcategoryName"));
    setRelation(CurrencyID, QSqlRelation("Currency", "CurrencyID", "CurrencyName"));
    setRelation(UOMID, QSqlRelation("UOM", "UOMID", "UOMName"));
    setRelation(RecommendationID, QSqlRelation("Recommendation", "RecommendationID", "Recommendation"));
    setRelation(ExpTypeID, QSqlRelation("ExpType", "ExpTypeID", "ExpTypeName"));
    setRelation(NatureID, QSqlRelation("Nature", "NatureID", "NatureName"));
    setRelation(FrequencyID, QSqlRelation("Frequency", "FrequencyID", "FrequencyName"));
    setRelation(OriginID, QSqlRelation("Origin", "OriginID", "OriginName"));
    setRelation(VendorID, QSqlRelation("Vendor", "VendorID", "VendorName"));
    setRelation(StatusID, QSqlRelation("Status", "StatusID", "StatusName"));
    setRelation(ApproverID, QSqlRelation("Approver", "ApproverID", "ApproverName"));


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
