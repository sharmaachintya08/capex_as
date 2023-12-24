#ifndef FORM_UOM_H
#define FORM_UOM_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modeluom.h"
namespace Ui {
class Form_uom;
}

class Form_uom : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_uom(QWidget *parent = nullptr);
    ~Form_uom();
    modeluom *modelUOM;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_uom *ui;
};

#endif // FORM_UOM_H
