#include "form_unit.h"
#include "ui_form_unit.h"

Form_unit::Form_unit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_unit)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelUnit = new modelunit(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_unit::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_unit::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_unit::closeAction);

    ui->tableView->setModel(modelUnit);

    ui->tableView->setColumnHidden(modelUnit->index_id, false);
    ui->tableView->setColumnHidden(modelUnit->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelUnit->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_unit::~Form_unit()
{
    delete ui;
}

void Form_unit::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelUnit->rowCount();
    modelIndex = modelUnit->create(row);
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

void Form_unit::saveAction()
{
    if (modelUnit->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_unit::closeAction()
{
    this->parentWidget()->close();
}
