#include "form_capex.h"
#include "ui_form_capex.h"

Form_capex::Form_capex(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_capex)
{
    ui->setupUi(this);
}

Form_capex::~Form_capex()
{
    delete ui;
}
