#include "form_locations.h"
#include "ui_form_locations.h"

Form_Locations::Form_Locations(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_Locations)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    modelLocation = new ModelLocation(this);

    connect(ui->pushButton_create, &QPushButton::clicked,
            this, &Form_Locations::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked,
            this, &Form_Locations::saveAction);
    connect(ui->pushButton_Close, &QPushButton::clicked,
            this, &Form_Locations::closeAction);

    ui->tableView->setModel(modelLocation);
    ui->tableView->setColumnHidden(modelLocation->index_id, false);
    ui->tableView->setColumnHidden(modelLocation->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelLocation->selectData();

    ui->tableView->resizeColumnToContents(0);
    ui->tableView->resizeColumnToContents(1);
}

Form_Locations::~Form_Locations()
{
    delete ui;
}

void Form_Locations::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelLocation->rowCount();
    qDebug() << "DEBUG: WidgetUnits::createAction rowCount: " << row;
    modelIndex = modelLocation->create(row);
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

void Form_Locations::saveAction()
{
    if (modelLocation->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_Locations::closeAction()
{
    this->parentWidget()->close();
}
