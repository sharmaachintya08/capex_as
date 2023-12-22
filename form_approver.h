#ifndef FORM_APPROVER_H
#define FORM_APPROVER_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelapprover.h"

namespace Ui {
class Form_approver;
}

class Form_approver : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_approver(QWidget *parent = nullptr);
    ~Form_approver();

private:
    Ui::Form_approver *ui;
    ModelApprover *modelApprover;
    QItemSelectionModel *selectionModel;
};

#endif // FORM_APPROVER_H
