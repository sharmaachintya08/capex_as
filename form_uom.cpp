#include "form_uom.h"
#include "ui_form_uom.h"

Form_uom::Form_uom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_uom)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelUOM = new modeluom(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_uom::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_uom::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_uom::closeAction);

    ui->tableView->setModel(modelUOM);

    ui->tableView->setColumnHidden(modelUOM->index_id, false);
    ui->tableView->setColumnHidden(modelUOM->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelUOM->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_uom::~Form_uom()
{
    delete ui;
}

void Form_uom::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelUOM->rowCount();
    modelIndex = modelUOM->create(row);
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

void Form_uom::saveAction()
{
    if (modelUOM->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_uom::closeAction()
{
    this->parentWidget()->close();
}
