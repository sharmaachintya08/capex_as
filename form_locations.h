#ifndef FORM_LOCATIONS_H
#define FORM_LOCATIONS_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modellocation.h"

namespace Ui {
class Form_Locations;
}

class Form_Locations : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Locations(QWidget *parent = nullptr);
    ~Form_Locations();

private slots:

    void createAction();
    void saveAction();
    void closeAction();

private:
    Ui::Form_Locations *ui;
    ModelLocation *modelLocation;
    QItemSelectionModel *selectionModel;
};

#endif // FORM_LOCATIONS_H
