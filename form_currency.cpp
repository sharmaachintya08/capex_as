#include "form_currency.h"
#include "ui_form_currency.h"

Form_currency::Form_currency(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_currency)
{
    ui->setupUi(this);
}

Form_currency::~Form_currency()
{
    delete ui;
}
