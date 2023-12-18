#ifndef FORM_RECOMMENDATION_H
#define FORM_RECOMMENDATION_H

#include <QWidget>

namespace Ui {
class Form_recommendation;
}

class Form_recommendation : public QWidget
{
    Q_OBJECT

public:
    explicit Form_recommendation(QWidget *parent = nullptr);
    ~Form_recommendation();

private:
    Ui::Form_recommendation *ui;
};

#endif // FORM_RECOMMENDATION_H
