#include "form_subcategory.h"
#include "ui_form_subcategory.h"

Form_subcategory::Form_subcategory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_subcategory)
{
    ui->setupUi(this);
}

Form_subcategory::~Form_subcategory()
{
    delete ui;
}
