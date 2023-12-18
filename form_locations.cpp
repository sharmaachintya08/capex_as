#include "form_locations.h"
#include "ui_form_locations.h"

Form_Locations::Form_Locations(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form_Locations)
{
    ui->setupUi(this);
}

Form_Locations::~Form_Locations()
{
    delete ui;
}
