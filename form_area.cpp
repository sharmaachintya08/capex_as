#include "form_area.h"
#include "ui_form_area.h"

Form_area::Form_area(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_area)
{
    ui->setupUi(this);
}

Form_area::~Form_area()
{
    delete ui;
}
