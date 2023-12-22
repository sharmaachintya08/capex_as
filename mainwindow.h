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
};
#endif // MAINWINDOW_H
