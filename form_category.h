#ifndef FORM_CATEGORY_H
#define FORM_CATEGORY_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelcategory.h"

namespace Ui {
class Form_category;
}

class Form_category : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_category(QWidget *parent = nullptr);
    ~Form_category();
    modelcategory *modelCategory;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_category *ui;
};

#endif // FORM_CATEGORY_H
