#include "MP.h"

MP::MP()
{
}

MP::MP(int id, const QString &name, const QString &salutation,
       const QString &job_title, const QString &electorate,
       const QString &party, const QString &parliament_email):
    id(id), name(name), salutation(salutation),
    job_title(job_title), electorate(electorate),
    party(party), parliament_email(parliament_email)
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
