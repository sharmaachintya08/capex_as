#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("capex.sqlite");

    if (!db.open()){
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }
    return true;
}

#endif // DB_H
