#ifndef FORM_VENDORS_H
#define FORM_VENDORS_H

#include <QWidget>

namespace Ui {
class Form_vendors;
}

class Form_vendors : public QWidget
{
    Q_OBJECT

public:
    explicit Form_vendors(QWidget *parent = nullptr);
    ~Form_vendors();

private:
    Ui::Form_vendors *ui;
};

#endif // FORM_VENDORS_H
