#include "form_capex.h"
#include "ui_form_capex.h"
#include <QSqlRelationalDelegate>

Form_capex::Form_capex(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_capex)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    modelCapex = new modelcapex(this);

    QSqlRelationalDelegate *delegate = new QSqlRelationalDelegate(this);
    ui->tableView->setItemDelegate(delegate);

    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_capex::submitAction);
    connect(ui->pushButton_close, &QPushButton::clicked, this, &Form_capex::closeAction);
    connect(ui->pushButton_create, &QPushButton::clicked, this, &Form_capex::createAction);

    ui->tableView->setModel(modelCapex);

    ui->tableView->setColumnHidden(modelCapex->index_id, false);
    ui->tableView->setColumnHidden(modelCapex->index_name, false);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    modelCapex->selectData();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeColumnsToContents();
}

Form_capex::~Form_capex()
{
    delete ui;
}


void Form_capex::submitAction()
{
    if (modelCapex->save())
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction successful.";
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnit::saveAction failed.";
    }
}

void Form_capex::closeAction()
{
    this->parentWidget()->close();
}

void Form_capex::createAction()
{
    QModelIndex modelIndex = QModelIndex();
    const int row = modelCapex->rowCount();
    modelIndex = modelCapex->create(row);
    if(modelIndex.isValid())
    {
        qDebug() << "DEBUG: WidgetUnits::creatAction valid Index: " << modelIndex;
        ui->tableView->setCurrentIndex(modelIndex);
    }
    else
    {
        qDebug() << "DEBUG: WidgetUnits::createAction Invalid Index: " << modelIndex;
    }
}
