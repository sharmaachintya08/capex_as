#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form_locations.h"
#include "form_approver.h"
#include "form_area.h"
#include "form_category.h"
#include "form_currency.h"
#include "form_exptype.h"
#include "form_frequency.h"
#include "form_nature.h"
#include "form_origin.h"
#include "form_recommendation.h"
#include "form_status.h"
#include "form_subcategory.h"
#include "form_unit.h"
#include "form_uom.h"
#include "form_vendors.h"
#include "form_capex.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionLocation, &QAction::triggered, this, &MainWindow::openLocationChildWidget);
    connect(ui->actionApprover, &QAction::triggered, this, &MainWindow::openApproverChildWidget);
    connect(ui->actionArea, &QAction::triggered, this, &MainWindow::openAreaChildWidget);
    connect(ui->actionCategory, &QAction::triggered, this, &MainWindow::openCategoryChildWidget);
    connect(ui->actionCurrency, &QAction::triggered, this, &MainWindow::openCurrencyChildWidget);
    connect(ui->actionExpType, &QAction::triggered, this, &MainWindow::openExpTypeChildWidget);
    connect(ui->actionFrequency, &QAction::triggered, this, &MainWindow::openFrequencyChildWidget);
    connect(ui->actionNature, &QAction::triggered, this, &MainWindow::openNatureChildWidget);
    connect(ui->actionOrigin, &QAction::triggered, this, &MainWindow::openOriginChildWidget);
    connect(ui->actionRecommendation, &QAction::triggered, this, &MainWindow::openRecommendationChildWidget);
    connect(ui->actionStatus, &QAction::triggered, this, &MainWindow::openStatusChildWidget);
    connect(ui->actionSubCategory, &QAction::triggered, this, &MainWindow::openSubCategoryChildWidget);
    connect(ui->actionUnit, &QAction::triggered, this, &MainWindow::openUnitChildWidget);
    connect(ui->actionUom, &QAction::triggered, this, &MainWindow::openUomChildWidget);
    connect(ui->actionVendor, &QAction::triggered, this, &MainWindow::openVendorsChildWidget);
    connect(ui->actionCapex_2, &QAction::triggered, this, &MainWindow::openCapexChildWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCapexChildWidget()
{
    Form_capex *formCapex = new Form_capex(this);
    ui->mdiArea->addSubWindow(formCapex);
    formCapex->show();
}
void MainWindow::openLocationChildWidget()
{
    Form_Locations *formLocations = new Form_Locations(this);
    ui->mdiArea->addSubWindow(formLocations);
    formLocations->show();
}

void MainWindow::openApproverChildWidget()
{
    Form_approver *form_approver = new Form_approver(this);
    ui->mdiArea->addSubWindow(form_approver);
    form_approver->show();
}

void MainWindow::openAreaChildWidget()
{
    Form_area *form_area = new Form_area(this);
    ui->mdiArea->addSubWindow(form_area);
    form_area->show();
}

void MainWindow::openCategoryChildWidget()
{
    Form_category *form_category = new Form_category(this);
    ui->mdiArea->addSubWindow(form_category);
    form_category->show();
}

void MainWindow::openCurrencyChildWidget()
{
    Form_currency *form_currency = new Form_currency(this);
    ui->mdiArea->addSubWindow(form_currency);
    form_currency->show();
}

void MainWindow::openExpTypeChildWidget()
{
    Form_exptype *form_exptype = new Form_exptype(this);
    ui->mdiArea->addSubWindow(form_exptype);
    form_exptype->show();
}

void MainWindow::openFrequencyChildWidget()
{
    Form_frequency *form_frequency = new Form_frequency(this);
    ui->mdiArea->addSubWindow(form_frequency);
    form_frequency->show();
}

void MainWindow::openNatureChildWidget()
{
    Form_nature *form_nature = new Form_nature(this);
    ui->mdiArea->addSubWindow(form_nature);
    form_nature->show();
}

void MainWindow::openOriginChildWidget()
{
    Form_origin *form_origin = new Form_origin(this);
    ui->mdiArea->addSubWindow(form_origin);
    form_origin->show();
}

void MainWindow::openRecommendationChildWidget()
{
    Form_recommendation *form_recommendation = new Form_recommendation(this);
    ui->mdiArea->addSubWindow(form_recommendation);
    form_recommendation->show();
}

void MainWindow::openStatusChildWidget()
{
    Form_status *form_status = new Form_status(this);
    ui->mdiArea->addSubWindow(form_status);
    form_status->show();
}

void MainWindow::openSubCategoryChildWidget()
{
    Form_subcategory *form_subcategory = new Form_subcategory(this);
    ui->mdiArea->addSubWindow(form_subcategory);
    form_subcategory->show();
}

void MainWindow::openUnitChildWidget()
{
    Form_unit *form_unit = new Form_unit(this);
    ui->mdiArea->addSubWindow(form_unit);
    form_unit->show();
}

void MainWindow::openUomChildWidget()
{
    Form_uom *form_uom = new Form_uom(this);
    ui->mdiArea->addSubWindow(form_uom);
    form_uom->show();
}

void MainWindow::openVendorsChildWidget()
{
    Form_vendors *form_vendors = new Form_vendors(this);
    ui->mdiArea->addSubWindow(form_vendors);
    form_vendors->show();
}
