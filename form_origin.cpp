#include "form_origin.h"
#include "ui_form_origin.h"

Form_origin::Form_origin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_origin)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelOrigin = new modelorigin(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_origin::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_origin::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_origin::closeAction);

    ui->tableView->setModel(modelOrigin);

    ui->tableView->setColumnHidden(modelOrigin->index_id, false);
    ui->tableView->setColumnHidden(modelOrigin->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelOrigin->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_origin::~Form_origin()
{
    delete ui;
}

void Form_origin::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelOrigin->rowCount();
    modelIndex = modelOrigin->create(row);
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

void Form_origin::saveAction()
{
    if (modelOrigin->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_origin::closeAction()
{
    this->parentWidget()->close();
}
