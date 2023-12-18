#include "form_status.h"
#include "ui_form_status.h"

Form_status::Form_status(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_status)
{
    ui->setupUi(this);
}

Form_status::~Form_status()
{
    delete ui;
}
