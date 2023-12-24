#ifndef FORM_FREQUENCY_H
#define FORM_FREQUENCY_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelfrequency.h"

namespace Ui {
class Form_frequency;
}

class Form_frequency : public QWidget
{
    Q_OBJECT

private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_frequency(QWidget *parent = nullptr);
    ~Form_frequency();
    modelfrequency *modelFrequency;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_frequency *ui;
};

#endif // FORM_FREQUENCY_H
