#include "form_nature.h"
#include "ui_form_nature.h"

Form_nature::Form_nature(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_nature)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelNature = new modelnature(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_nature::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_nature::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_nature::closeAction);

    ui->tableView->setModel(modelNature);

    ui->tableView->setColumnHidden(modelNature->index_id, false);
    ui->tableView->setColumnHidden(modelNature->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelNature->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_nature::~Form_nature()
{
    delete ui;
}

void Form_nature::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelNature->rowCount();
    modelIndex = modelNature->create(row);
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

void Form_nature::saveAction()
{
    if (modelNature->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_nature::closeAction()
{
    this->parentWidget()->close();
}
