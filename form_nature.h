#ifndef FORM_NATURE_H
#define FORM_NATURE_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelnature.h"

namespace Ui {
class Form_nature;
}

class Form_nature : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_nature(QWidget *parent = nullptr);
    ~Form_nature();
    modelnature *modelNature;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_nature *ui;
};

#endif // FORM_NATURE_H
