#ifndef FORM_VENDORS_H
#define FORM_VENDORS_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelvendor.h"

namespace Ui {
class Form_vendors;
}

class Form_vendors : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_vendors(QWidget *parent = nullptr);
    ~Form_vendors();
    modelvendor *modelVendor;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_vendors *ui;
};

#endif // FORM_VENDORS_H
