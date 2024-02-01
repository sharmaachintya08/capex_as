#ifndef FORM_CAPEX_H
#define FORM_CAPEX_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelcapex.h"

namespace Ui {
class Form_capex;
}

class Form_capex : public QWidget
{
    Q_OBJECT


private slots:
    void submitAction();
    void closeAction();
    void createAction();

public:
    explicit Form_capex(QWidget *parent = nullptr);
    ~Form_capex();
    modelcapex *modelCapex;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_capex *ui;
};


#endif // FORM_CAPEX_H
