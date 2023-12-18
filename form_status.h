#ifndef FORM_STATUS_H
#define FORM_STATUS_H

#include <QWidget>

namespace Ui {
class Form_status;
}

class Form_status : public QWidget
{
    Q_OBJECT

public:
    explicit Form_status(QWidget *parent = nullptr);
    ~Form_status();

private:
    Ui::Form_status *ui;
};

#endif // FORM_STATUS_H
