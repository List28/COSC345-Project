#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <dbmanager.h>

// Change to any path you wish
static const QString path = "example.db";

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DbManager db(path);

    if (db.isOpen())
    {
        db.createMpsTable();
        db.printAllMps();
        /*
        db.createTable();   // Creates a table if it doens't exist. Otherwise, it will use existing table.
        db.addPerson("A");
        db.addPerson("B");
        db.addPerson("C");
        db.printAllPersons();
        db.removePerson("C");
        db.printAllPersons();
        db.removeAllPersons();*/
        qDebug() << "End";
    }
    else
    {
        qDebug() << "Database is not open!";
    }

    return a.exec();
}
