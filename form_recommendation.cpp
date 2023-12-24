#include "form_recommendation.h"
#include "ui_form_recommendation.h"

Form_recommendation::Form_recommendation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_recommendation)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    modelRecommendation = new modelrecommendation(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_recommendation::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_recommendation::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_recommendation::closeAction);

    ui->tableView->setModel(modelRecommendation);

    ui->tableView->setColumnHidden(modelRecommendation->index_id, false);
    ui->tableView->setColumnHidden(modelRecommendation->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelRecommendation->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();


}

Form_recommendation::~Form_recommendation()
{
    delete ui;
}

void Form_recommendation::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelRecommendation->rowCount();
    modelIndex = modelRecommendation->create(row);
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

void Form_recommendation::saveAction()
{
    if (modelRecommendation->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_recommendation::closeAction()
{
    this->parentWidget()->close();
}
