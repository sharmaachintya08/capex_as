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

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
    void maintainLocation();
    Form_Locations *formLocations;
    Form_approver *form_approver;
    Form_area *Formarea;
    Form_category *Formcategory;
    Form_currency *FormCurrency;
};
#endif // MAINWINDOW_H
