#include "form_area.h"
#include "ui_form_area.h"

Form_area::Form_area(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_area)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    modelArea = new modelarea(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_area::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_area::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_area::closeAction);

    ui->tableView->setModel(modelArea);

    ui->tableView->setColumnHidden(modelArea->index_id, false);
    ui->tableView->setColumnHidden(modelArea->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelArea->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();

}

Form_area::~Form_area()
{
    delete ui;
}

void Form_area::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelArea->rowCount();
    modelIndex = modelArea->create(row);
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

void Form_area::saveAction()
{
    if (modelArea->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_area::closeAction()
{
    this->parentWidget()->close();
}
