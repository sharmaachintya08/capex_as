#ifndef FORM_CATEGORY_H
#define FORM_CATEGORY_H

#include <QWidget>

namespace Ui {
class Form_category;
}

class Form_category : public QWidget
{
    Q_OBJECT

public:
    explicit Form_category(QWidget *parent = nullptr);
    ~Form_category();

private:
    Ui::Form_category *ui;
};

#endif // FORM_CATEGORY_H
