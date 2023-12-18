#ifndef FORM_CURRENCY_H
#define FORM_CURRENCY_H

#include <QWidget>

namespace Ui {
class Form_currency;
}

class Form_currency : public QWidget
{
    Q_OBJECT

public:
    explicit Form_currency(QWidget *parent = nullptr);
    ~Form_currency();

private:
    Ui::Form_currency *ui;
};

#endif // FORM_CURRENCY_H
