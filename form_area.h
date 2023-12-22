#ifndef FORM_AREA_H
#define FORM_AREA_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelarea.h"

namespace Ui {
class Form_area;
}

class Form_area : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();
public:
    explicit Form_area(QWidget *parent = nullptr);
    ~Form_area();
    modelarea *modelArea;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_area *ui;
};

#endif // FORM_AREA_H
