#ifndef FORM_NATURE_H
#define FORM_NATURE_H

#include <QWidget>

namespace Ui {
class Form_nature;
}

class Form_nature : public QWidget
{
    Q_OBJECT

public:
    explicit Form_nature(QWidget *parent = nullptr);
    ~Form_nature();

private:
    Ui::Form_nature *ui;
};

#endif // FORM_NATURE_H
