#ifndef FORM_UNIT_H
#define FORM_UNIT_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelunit.h"

namespace Ui {
class Form_unit;
}

class Form_unit : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_unit(QWidget *parent = nullptr);
    ~Form_unit();
    modelunit *modelUnit;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_unit *ui;
};

#endif // FORM_UNIT_H
