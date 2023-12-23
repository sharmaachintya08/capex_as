#include "form_category.h"
#include "ui_form_category.h"

Form_category::Form_category(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_category)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelCategory = new modelcategory(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_category::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_category::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_category::closeAction);

    ui->tableView->setModel(modelCategory);

    ui->tableView->setColumnHidden(modelCategory->index_id, false);
    ui->tableView->setColumnHidden(modelCategory->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelCategory->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_category::~Form_category()
{
    delete ui;
}

void Form_category::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelCategory->rowCount();
    modelIndex = modelCategory->create(row);
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

void Form_category::saveAction()
{
    if (modelCategory->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_category::closeAction()
{
    this->parentWidget()->close();
}
