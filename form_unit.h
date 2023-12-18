#ifndef FORM_UNIT_H
#define FORM_UNIT_H

#include <QWidget>

namespace Ui {
class Form_unit;
}

class Form_unit : public QWidget
{
    Q_OBJECT

public:
    explicit Form_unit(QWidget *parent = nullptr);
    ~Form_unit();

private:
    Ui::Form_unit *ui;
};

#endif // FORM_UNIT_H
