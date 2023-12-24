#ifndef FORM_STATUS_H
#define FORM_STATUS_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelstatus.h"

namespace Ui {
class Form_status;
}

class Form_status : public QWidget
{
    Q_OBJECT


private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_status(QWidget *parent = nullptr);
    ~Form_status();
    modelstatus *modelStatus;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_status *ui;
};

#endif // FORM_STATUS_H
