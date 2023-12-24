#include "form_status.h"
#include "ui_form_status.h"

Form_status::Form_status(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_status)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelStatus = new modelstatus(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_status::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_status::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_status::closeAction);

    ui->tableView->setModel(modelStatus);

    ui->tableView->setColumnHidden(modelStatus->index_id, false);
    ui->tableView->setColumnHidden(modelStatus->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelStatus->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_status::~Form_status()
{
    delete ui;
}

void Form_status::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelStatus->rowCount();
    modelIndex = modelStatus->create(row);
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

void Form_status::saveAction()
{
    if (modelStatus->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_status::closeAction()
{
    this->parentWidget()->close();
}
