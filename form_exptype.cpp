#include "form_exptype.h"
#include "ui_form_exptype.h"

Form_exptype::Form_exptype(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_exptype)
{
    ui->setupUi(this);
}

Form_exptype::~Form_exptype()
{
    delete ui;
}
