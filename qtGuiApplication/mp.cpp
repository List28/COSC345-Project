#include "MP.h"

MP::MP()
{
}

MP::MP(int id, const QString &name, const QString &salutation,
       const QString &job_title, const QString &electorate,
       const QString &party, const QString &parliament_email, const Finances finances):
    id(id), name(name), salutation(salutation),
    job_title(job_title), electorate(electorate),
    party(party), parliament_email(parliament_email), finances(finances)
{
}

int MP::getId() const
{
    return id;
}

QString MP::getName() const
{
    return name;
}

QString MP::getSalutation() const
{
    return salutation;
}

QString MP::getJobTitle() const
{
    return job_title;
}

QString MP::getElectorate() const
{
    return electorate;
}

QString MP::getParty() const
{
    return party;
}

QString MP::getParliamentEmail() const
{
    return parliament_email;
}

Finances MP::getFinances() const
{
    return finances;
}
