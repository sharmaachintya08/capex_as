#include "form_nature.h"
#include "ui_form_nature.h"

Form_nature::Form_nature(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_nature)
{
    ui->setupUi(this);
}

Form_nature::~Form_nature()
{
    delete ui;
}
