#ifndef FORM_LOCATIONS_H
#define FORM_LOCATIONS_H

#include <QWidget>

namespace Ui {
class Form_Locations;
}

class Form_Locations : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Locations(QWidget *parent = nullptr);
    ~Form_Locations();

private:
    Ui::Form_Locations *ui;
};

#endif // FORM_LOCATIONS_H
