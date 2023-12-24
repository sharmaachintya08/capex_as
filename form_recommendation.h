#ifndef FORM_RECOMMENDATION_H
#define FORM_RECOMMENDATION_H

#include <QWidget>
#include <QMessageBox>
#include <QString>
#include <QItemSelectionModel>

#include "modelrecommendation.h"

namespace Ui {
class Form_recommendation;
}

class Form_recommendation : public QWidget
{
    Q_OBJECT


private slots:

    void createAction();
    void saveAction();
    void closeAction();

public:
    explicit Form_recommendation(QWidget *parent = nullptr);
    ~Form_recommendation();
    modelrecommendation *modelRecommendation;
    QItemSelectionModel *selectionModel;

private:
    Ui::Form_recommendation *ui;
};

#endif // FORM_RECOMMENDATION_H
