#ifndef FORM_APPROVER_H
#define FORM_APPROVER_H

#include <QWidget>

namespace Ui {
class Form_approver;
}

class Form_approver : public QWidget
{
    Q_OBJECT

public:
    explicit Form_approver(QWidget *parent = nullptr);
    ~Form_approver();

private:
    Ui::Form_approver *ui;
};

#endif // FORM_APPROVER_H
