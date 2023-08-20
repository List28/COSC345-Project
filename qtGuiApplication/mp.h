#ifndef MP_H
#define MP_H

#include <QString>
#include "finances.h"

class MP
{
public:
    MP();
    MP(int id, const QString &name, const QString &salutation,
       const QString &job_title, const QString &electorate,
       const QString &party, const QString &parliament_email, const Finances finances);

    int getId() const;
    QString getName() const;
    QString getSalutation() const;
    QString getJobTitle() const;
    QString getElectorate() const;
    QString getParty() const;
    QString getParliamentEmail() const;
    Finances getFinances() const;

private:
    int id;
    QString name;
    QString salutation;
    QString job_title;
    QString electorate;
    QString party;
    QString parliament_email;
    Finances finances;
};

#endif // MP_H
