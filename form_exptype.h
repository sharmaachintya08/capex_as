#ifndef FORM_EXPTYPE_H
#define FORM_EXPTYPE_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelexptype.h"

namespace Ui {
class Form_exptype;
}

class Form_exptype : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_exptype(QWidget *parent = nullptr);
    ~Form_exptype();
    modelexptype *modelExptype;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_exptype *ui;
};

#endif // FORM_EXPTYPE_H
