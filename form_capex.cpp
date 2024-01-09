#include "form_capex.h"
#include "ui_form_capex.h"

Form_capex::Form_capex(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_capex)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    modelCapex = new modelcapex(this);

    connect(ui->pushButton_submit, &QPushButton::clicked, this, &Form_capex::submitAction);
    connect(ui->pushButton_close, &QPushButton::clicked, this, &Form_capex::closeAction);

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
