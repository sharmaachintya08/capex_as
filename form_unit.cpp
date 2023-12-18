#include "form_unit.h"
#include "ui_form_unit.h"

Form_unit::Form_unit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_unit)
{
    ui->setupUi(this);
}

Form_unit::~Form_unit()
{
    delete ui;
}
