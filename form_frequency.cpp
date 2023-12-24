#include "form_frequency.h"
#include "ui_form_frequency.h"

Form_frequency::Form_frequency(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_frequency)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelFrequency = new modelfrequency(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_frequency::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_frequency::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_frequency::closeAction);

    ui->tableView->setModel(modelFrequency);

    ui->tableView->setColumnHidden(modelFrequency->index_id, false);
    ui->tableView->setColumnHidden(modelFrequency->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelFrequency->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();
}

Form_frequency::~Form_frequency()
{
    delete ui;
}

void Form_frequency::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelFrequency->rowCount();
    modelIndex = modelFrequency->create(row);
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

void Form_frequency::saveAction()
{
    if (modelFrequency->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_frequency::closeAction()
{
    this->parentWidget()->close();
}
