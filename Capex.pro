QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form_approver.cpp \
    form_area.cpp \
    form_category.cpp \
    form_currency.cpp \
    form_exptype.cpp \
    form_frequency.cpp \
    form_locations.cpp \
    form_nature.cpp \
    form_origin.cpp \
    form_recommendation.cpp \
    form_status.cpp \
    form_subcategory.cpp \
    form_unit.cpp \
    form_uom.cpp \
    form_vendors.cpp \
    main.cpp \
    mainwindow.cpp \
    modellocation.cpp

HEADERS += \
    db.h \
    form_approver.h \
    form_area.h \
    form_category.h \
    form_currency.h \
    form_exptype.h \
    form_frequency.h \
    form_locations.h \
    form_nature.h \
    form_origin.h \
    form_recommendation.h \
    form_status.h \
    form_subcategory.h \
    form_unit.h \
    form_uom.h \
    form_vendors.h \
    mainwindow.h \
    modellocation.h

FORMS += \
    form_approver.ui \
    form_area.ui \
    form_category.ui \
    form_currency.ui \
    form_exptype.ui \
    form_frequency.ui \
    form_locations.ui \
    form_nature.ui \
    form_origin.ui \
    form_recommendation.ui \
    form_status.ui \
    form_subcategory.ui \
    form_unit.ui \
    form_uom.ui \
    form_vendors.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    capex.sqlite

RESOURCES += \
    icons.qrc
