#ifndef FORM_EXPTYPE_H
#define FORM_EXPTYPE_H

#include <QWidget>

namespace Ui {
class Form_exptype;
}

class Form_exptype : public QWidget
{
    Q_OBJECT

public:
    explicit Form_exptype(QWidget *parent = nullptr);
    ~Form_exptype();

private:
    Ui::Form_exptype *ui;
};

#endif // FORM_EXPTYPE_H
