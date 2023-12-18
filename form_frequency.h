#ifndef FORM_FREQUENCY_H
#define FORM_FREQUENCY_H

#include <QWidget>

namespace Ui {
class Form_frequency;
}

class Form_frequency : public QWidget
{
    Q_OBJECT

public:
    explicit Form_frequency(QWidget *parent = nullptr);
    ~Form_frequency();

private:
    Ui::Form_frequency *ui;
};

#endif // FORM_FREQUENCY_H
