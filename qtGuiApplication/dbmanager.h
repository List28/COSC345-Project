#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

#include "mp.h"

class DbManager
{
public:
    
    DbManager(const QString& path);

    ~DbManager();

    bool isOpen() const;

    // Creates mps table from csv file
    bool createMpsTable();

    std::vector<MP> getAllMps();

    MP getMpFromName(const QString& name);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
