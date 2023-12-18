#include "form_recommendation.h"
#include "ui_form_recommendation.h"

Form_recommendation::Form_recommendation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_recommendation)
{
    ui->setupUi(this);
}

Form_recommendation::~Form_recommendation()
{
    delete ui;
}
