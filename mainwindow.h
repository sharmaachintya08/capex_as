#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qmdiarea.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void openLocationChildWidget();
    void openApproverChildWidget();
    void openAreaChildWidget();
    void openCategoryChildWidget();
    void openCurrencyChildWidget();
    void openExpTypeChildWidget();
    void openFrequencyChildWidget();
    void openNatureChildWidget();
    void openOriginChildWidget();
    void openRecommendationChildWidget();
    void openStatusChildWidget();
    void openSubCategoryChildWidget();
    void openUnitChildWidget();
    void openUomChildWidget();
    void openVendorsChildWidget();
    void openCapexChildWidget();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
    void maintainLocation();
    Form_Locations *formLocations;
    Form_approver *form_approver;
    Form_area *Formarea;
    Form_category *Formcategory;
    Form_currency *FormCurrency;
    Form_exptype *FormExptype;
    Form_frequency *formFrequency;
    Form_nature *formNature;
    Form_origin *formOrigin;
    Form_recommendation *formRecommendation;
    Form_status *formStatus;
    Form_subcategory *FormSubcategory;
    Form_unit *FormUnit;
    Form_uom *formUOM;
    Form_vendors *formVendor;
    Form_capex *formCapex;
};
#endif // MAINWINDOW_H
