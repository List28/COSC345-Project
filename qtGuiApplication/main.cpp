#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <dbmanager.h>


static const QString path = "parliament.db";

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DbManager db(path);

    if (db.isOpen())
    {
        db.createMpsTable();
        std::vector<MP> mps = db.getAllMps();
        for (size_t i = 0; i < mps.size(); ++i) {
            qDebug() << "===" << mps[i].getName();
            qDebug() << "===" << mps[i].getElectorate();
        }

        MP jamie = db.getMpFromName("Strange Jamie");
        qDebug() << "===" << jamie.getName();

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
