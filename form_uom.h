#ifndef FORM_UOM_H
#define FORM_UOM_H

#include <QWidget>

namespace Ui {
class Form_uom;
}

class Form_uom : public QWidget
{
    Q_OBJECT

public:
    explicit Form_uom(QWidget *parent = nullptr);
    ~Form_uom();

private:
    Ui::Form_uom *ui;
};

#endif // FORM_UOM_H
