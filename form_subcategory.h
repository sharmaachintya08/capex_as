#ifndef FORM_SUBCATEGORY_H
#define FORM_SUBCATEGORY_H

#include <QWidget>

namespace Ui {
class Form_subcategory;
}

class Form_subcategory : public QWidget
{
    Q_OBJECT

public:
    explicit Form_subcategory(QWidget *parent = nullptr);
    ~Form_subcategory();

private:
    Ui::Form_subcategory *ui;
};

#endif // FORM_SUBCATEGORY_H
