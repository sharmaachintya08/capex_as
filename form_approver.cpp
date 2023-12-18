#include "form_approver.h"
#include "ui_form_approver.h"

Form_approver::Form_approver(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_approver)
{
    ui->setupUi(this);
}

Form_approver::~Form_approver()
{
    delete ui;
}
