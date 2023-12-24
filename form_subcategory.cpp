#include "form_subcategory.h"
#include "ui_form_subcategory.h"

Form_subcategory::Form_subcategory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_subcategory)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelSubcategory = new modelsubcategory(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_subcategory::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_subcategory::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_subcategory::closeAction);

    ui->tableView->setModel(modelSubcategory);

    ui->tableView->setColumnHidden(modelSubcategory->index_id, false);
    ui->tableView->setColumnHidden(modelSubcategory->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelSubcategory->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_subcategory::~Form_subcategory()
{
    delete ui;
}

void Form_subcategory::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelSubcategory->rowCount();
    modelIndex = modelSubcategory->create(row);
    if (modelIndex.isValid())
    {
        qDebug() << "DEBUG: WidgetUnits::createAction Valid Index: " << modelIndex;
        ui->tableView->setCurrentIndex(modelIndex);
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnits::createAction Invalid Index: " << modelIndex;
    }
}

void Form_subcategory::saveAction()
{
    if (modelSubcategory->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_subcategory::closeAction()
{
    this->parentWidget()->close();
}
