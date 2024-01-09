#ifndef FORM_CAPEX_H
#define FORM_CAPEX_H

#include <QWidget>

namespace Ui {
class Form_capex;
}

class Form_capex : public QWidget
{
    Q_OBJECT

public:
    explicit Form_capex(QWidget *parent = nullptr);
    ~Form_capex();

private:
    Ui::Form_capex *ui;
};


#endif // FORM_CAPEX_H
