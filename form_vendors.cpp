#include "form_vendors.h"
#include "ui_form_vendors.h"

Form_vendors::Form_vendors(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_vendors)
{
    ui->setupUi(this);
}

Form_vendors::~Form_vendors()
{
    delete ui;
}
