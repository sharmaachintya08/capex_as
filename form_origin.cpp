#include "form_origin.h"
#include "ui_form_origin.h"

Form_origin::Form_origin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_origin)
{
    ui->setupUi(this);
}

Form_origin::~Form_origin()
{
    delete ui;
}
