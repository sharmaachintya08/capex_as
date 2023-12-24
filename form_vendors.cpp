#include "form_vendors.h"
#include "ui_form_vendors.h"

Form_vendors::Form_vendors(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_vendors)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelVendor = new modelvendor(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_vendors::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_vendors::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_vendors::closeAction);

    ui->tableView->setModel(modelVendor);

    ui->tableView->setColumnHidden(modelVendor->index_id, false);
    ui->tableView->setColumnHidden(modelVendor->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelVendor->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_vendors::~Form_vendors()
{
    delete ui;
}

void Form_vendors::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelVendor->rowCount();
    modelIndex = modelVendor->create(row);
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

void Form_vendors::saveAction()
{
    if (modelVendor->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_vendors::closeAction()
{
    this->parentWidget()->close();
}
