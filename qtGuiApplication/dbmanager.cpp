#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <qevent.h>

#include <QFile>
#include <QTextStream>
#include <QStringList>

#include "mp.h"
#include "finances.h"

DbManager::DbManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createMpsTable()
{
    QSqlQuery query;
    query.prepare("CREATE TABLE mps( id INT, name VARCHAR(50) PRIMARY KEY, salutation VARCHAR(10) NULL, job_title VARCHAR(50), electorate VARCHAR(50) NULL, party VARCHAR(30), parliament_email VARCHAR(70));");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'mps': one might already exist.";
        return false;
    }


    QFile file("../web-scrapers/transcripts-scraper/mp.csv");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return false;
    }

    QTextStream in(&file);

    // Read the first line to ignore the header
    if (!in.atEnd()) {
        in.readLine();
    }

    query.prepare("INSERT INTO mps (id, name, salutation, job_title, electorate, party, parliament_email) VALUES (?, ?, ?, ?, ?, ?, ?)");

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        query.addBindValue(fields[0].toInt());
        query.addBindValue((fields[2].remove(" ") + " " + fields[1]).remove("\""));
        query.addBindValue(fields[3] == "\"\"" ? NULL : fields[3]);
        query.addBindValue(fields[4]);
        query.addBindValue(fields[5] == "\"\"" ? NULL : fields[5]);
        query.addBindValue(fields[6]);
        query.addBindValue(fields[7]);

        if (!query.exec()) {
            qDebug() << "Error inserting data into table: " << query.lastError();
            return false;
        }
    }

    file.close();
    return true;
}

std::vector<MP> DbManager::getAllMps()
{
    std::vector<MP> allMps;
    qDebug() << "Persons in db:";
    //QSqlQuery query("SELECT * FROM mps");
    QSqlQuery query("SELECT mps.*, finances.* FROM mps JOIN Finances ON mps.name = Finances.mp_name;");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QStringList cd = query.value(8).toString().split("|");
        QStringList oc = query.value(9).toString().split("|");
        QStringList emp = query.value(10).toString().split("|");
        QStringList it = query.value(11).toString().split("|");
        QStringList orgs = query.value(12).toString().split("|");
        QStringList prop = query.value(13).toString().split("|");
        QStringList ret = query.value(14).toString().split("|");
        QStringList is = query.value(15).toString().split("|");
        QStringList to_you = query.value(16).toString().split("|");
        QStringList by_you = query.value(17).toString().split("|");
        QStringList os = query.value(18).toString().split("|");
        QStringList gifts = query.value(19).toString().split("|");
        QStringList pa = query.value(20).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you, os, gifts, pa);

        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
            query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), 
            query.value(6).toString(), finances);
        allMps.push_back(mp);
    }
    return allMps;
}

std::vector<MP> DbManager::getAllMpsFromParty(const QString& party)
{
    std::vector<MP> allMps;
    qDebug() << "Persons in db:";
    //QSqlQuery query("SELECT * FROM mps");
    QSqlQuery query;
    query.prepare("SELECT mps.*, finances.* FROM mps JOIN Finances ON mps.name = Finances.mp_name WHERE mps.party = ?;");
    query.bindValue(0, party);

    /**/
    if (query.exec()) {
        // Query executed successfully
        qDebug() << "Query executed successfully";
    }
    else {
        // Error occurred during query execution
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QStringList cd = query.value(8).toString().split("|");
        QStringList oc = query.value(9).toString().split("|");
        QStringList emp = query.value(10).toString().split("|");
        QStringList it = query.value(11).toString().split("|");
        QStringList orgs = query.value(12).toString().split("|");
        QStringList prop = query.value(13).toString().split("|");
        QStringList ret = query.value(14).toString().split("|");
        QStringList is = query.value(15).toString().split("|");
        QStringList to_you = query.value(16).toString().split("|");
        QStringList by_you = query.value(17).toString().split("|");
        QStringList os = query.value(18).toString().split("|");
        QStringList gifts = query.value(19).toString().split("|");
        QStringList pa = query.value(20).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you, os, gifts, pa);

        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
            query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), 
            query.value(6).toString(), finances);
        allMps.push_back(mp);
    }
    return allMps;
}


MP DbManager::getMpFromName(const QString& name)
{
    QSqlQuery query;
    //query.prepare("SELECT * FROM mps WHERE name = ?");
    query.prepare("SELECT mps.*, finances.* FROM mps JOIN Finances ON mps.name = Finances.mp_name WHERE mps.name = ?;");
    query.bindValue(0, name);

    if (query.exec() && query.next())
    {
        QStringList cd = query.value(8).toString().split("|");
        QStringList oc = query.value(9).toString().split("|");
        QStringList emp = query.value(10).toString().split("|");
        QStringList it = query.value(11).toString().split("|");
        QStringList orgs = query.value(12).toString().split("|");
        QStringList prop = query.value(13).toString().split("|");
        QStringList ret = query.value(14).toString().split("|");
        QStringList is = query.value(15).toString().split("|");
        QStringList to_you = query.value(16).toString().split("|");
        QStringList by_you = query.value(17).toString().split("|");
        QStringList os = query.value(18).toString().split("|");
        QStringList gifts = query.value(19).toString().split("|");
        QStringList pa = query.value(20).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you, os, gifts, pa);

        MP mp = MP(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(),
            query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
            query.value(6).toString(), finances);

        return mp;
        
    }
    else
    {
        qDebug() << "person exists failed: " << query.lastError();
        return MP();
    }
}

std::vector<Finances> DbManager::getAllFinances()
{
    std::vector<Finances> allFinances;
    qDebug() << "Finances in db:";
    QSqlQuery query("SELECT * FROM finances");
    int mp_name = query.record().indexOf("mp_name");
    while (query.next())
    {
        QStringList cd = query.value(1).toString().split("|");
        QStringList oc = query.value(2).toString().split("|");
        QStringList emp = query.value(3).toString().split("|");
        QStringList it = query.value(4).toString().split("|");
        QStringList orgs = query.value(5).toString().split("|");
        QStringList prop = query.value(6).toString().split("|");
        QStringList ret = query.value(7).toString().split("|");
        QStringList is = query.value(8).toString().split("|");
        QStringList to_you = query.value(9).toString().split("|");
        QStringList by_you = query.value(10).toString().split("|");
        QStringList os = query.value(11).toString().split("|");
        QStringList gifts = query.value(12).toString().split("|");
        QStringList pa = query.value(13).toString().split("|");

        Finances finances = Finances(query.value(0).toString(), cd, oc, emp, it, orgs, prop, ret, is, to_you, by_you,
            os, gifts, pa);
        allFinances.push_back(finances);
    }
    return allFinances;
}