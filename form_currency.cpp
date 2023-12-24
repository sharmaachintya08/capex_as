#include "form_currency.h"
#include "ui_form_currency.h"

Form_currency::Form_currency(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_currency)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelCurrency = new modelcurrency(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_currency::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_currency::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_currency::closeAction);

    ui->tableView->setModel(modelCurrency);

    ui->tableView->setColumnHidden(modelCurrency->index_id, false);
    ui->tableView->setColumnHidden(modelCurrency->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelCurrency->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_currency::~Form_currency()
{
    delete ui;
}

void Form_currency::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelCurrency->rowCount();
    modelIndex = modelCurrency->create(row);
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

void Form_currency::saveAction()
{
    if (modelCurrency->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_currency::closeAction()
{
    this->parentWidget()->close();
}
