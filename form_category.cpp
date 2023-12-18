#include "form_category.h"
#include "ui_form_category.h"

Form_category::Form_category(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_category)
{
    ui->setupUi(this);
}

Form_category::~Form_category()
{
    delete ui;
}
