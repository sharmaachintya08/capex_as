#include "form_frequency.h"
#include "ui_form_frequency.h"

Form_frequency::Form_frequency(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_frequency)
{
    ui->setupUi(this);
}

Form_frequency::~Form_frequency()
{
    delete ui;
}
