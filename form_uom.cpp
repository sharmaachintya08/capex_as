#include "form_uom.h"
#include "ui_form_uom.h"

Form_uom::Form_uom(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_uom)
{
    ui->setupUi(this);
}

Form_uom::~Form_uom()
{
    delete ui;
}
