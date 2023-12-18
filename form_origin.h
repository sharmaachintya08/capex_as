#ifndef FORM_ORIGIN_H
#define FORM_ORIGIN_H

#include <QWidget>

namespace Ui {
class Form_origin;
}

class Form_origin : public QWidget
{
    Q_OBJECT

public:
    explicit Form_origin(QWidget *parent = nullptr);
    ~Form_origin();

private:
    Ui::Form_origin *ui;
};

#endif // FORM_ORIGIN_H
