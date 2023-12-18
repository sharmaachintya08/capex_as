#ifndef FORM_AREA_H
#define FORM_AREA_H

#include <QWidget>

namespace Ui {
class Form_area;
}

class Form_area : public QWidget
{
    Q_OBJECT

public:
    explicit Form_area(QWidget *parent = nullptr);
    ~Form_area();

private:
    Ui::Form_area *ui;
};

#endif // FORM_AREA_H
