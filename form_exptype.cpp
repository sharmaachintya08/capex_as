#include "form_exptype.h"
#include "ui_form_exptype.h"

Form_exptype::Form_exptype(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_exptype)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelExptype = new modelexptype(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_exptype::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_exptype::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_exptype::closeAction);

    ui->tableView->setModel(modelExptype);

    ui->tableView->setColumnHidden(modelExptype->index_id, false);
    ui->tableView->setColumnHidden(modelExptype->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelExptype->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();
}

Form_exptype::~Form_exptype()
{
    delete ui;
}

void Form_exptype::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelExptype->rowCount();
    modelIndex = modelExptype->create(row);
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

void Form_exptype::saveAction()
{
    if (modelExptype->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_exptype::closeAction()
{
    this->parentWidget()->close();
}
