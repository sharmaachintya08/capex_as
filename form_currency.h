#ifndef FORM_CURRENCY_H
#define FORM_CURRENCY_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelcurrency.h"

namespace Ui {
class Form_currency;
}

class Form_currency : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_currency(QWidget *parent = nullptr);
    ~Form_currency();
    modelcurrency *modelCurrency;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_currency *ui;
};

#endif // FORM_CURRENCY_H
