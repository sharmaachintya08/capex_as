#ifndef FORM_ORIGIN_H
#define FORM_ORIGIN_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelorigin.h"

namespace Ui {
class Form_origin;
}

class Form_origin : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_origin(QWidget *parent = nullptr);
    ~Form_origin();
    modelorigin *modelOrigin;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_origin *ui;
};

#endif // FORM_ORIGIN_H
