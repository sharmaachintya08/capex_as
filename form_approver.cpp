#include "form_approver.h"
#include "ui_form_approver.h"

Form_approver::Form_approver(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_approver)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    modelApprover = new ModelApprover(this);

    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_approver::createAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_approver::saveAction);
    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_approver::closeAction);

    ui->tableView->setModel(modelApprover);
    ui->tableView->setColumnHidden(modelApprover->index_id, false);
    ui->tableView->setColumnHidden(modelApprover->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelApprover->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();

}

Form_approver::~Form_approver()
{
    delete ui;
}

void Form_approver::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelApprover->rowCount();
    modelIndex = modelApprover->create(row);
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

void Form_approver::saveAction()
{
    if (modelApprover->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_approver::closeAction()
{
    this->parentWidget()->close();
}
