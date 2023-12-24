#ifndef FORM_SUBCATEGORY_H
#define FORM_SUBCATEGORY_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelsubcategory.h"

namespace Ui {
class Form_subcategory;
}

class Form_subcategory : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_subcategory(QWidget *parent = nullptr);
    ~Form_subcategory();
    modelsubcategory *modelSubcategory;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_subcategory *ui;
};

#endif // FORM_SUBCATEGORY_H
