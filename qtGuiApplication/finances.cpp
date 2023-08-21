#include <QStringList>
#include "finances.h"

Finances::Finances()
{
}

Finances::Finances(const QString mp_name, const QStringList company_directorships, 
    const QStringList other_companies, const QStringList employment, const QStringList interest_trust, 
    const QStringList organizations, const QStringList property, const QStringList retirement,  
    const QStringList investment_schemes, const QStringList debts_to_you, const QStringList debts_owed_by_you, 
    const QStringList overseas_travel, const QStringList gifts, const QStringList payment_activities) :
    mp_name(mp_name), company_directorships(company_directorships), other_companies(other_companies),
    employment(employment), interest_trust(interest_trust), organizations(organizations), 
    property(property), retirement(retirement), investment_schemes(investment_schemes), 
    debts_to_you(debts_to_you), debts_owed_by_you(debts_owed_by_you), overseas_travel(overseas_travel),
    gifts(gifts), payment_activities(payment_activities)
{
}

QString Finances::getMpName() const
{
    return mp_name;
}

QStringList Finances::getCompanyDirectorships() const
{
    return company_directorships;
}

QStringList Finances::getOtherCompanies()
{
    return other_companies;
}

QStringList Finances::getEmployment()
{
    return employment;
}

QStringList Finances::getInterestTrust()
{
    return interest_trust;
}

QStringList Finances::getOrganizations()
{
    return organizations;
}

QStringList Finances::getProperty()
{
    return property;
}

QStringList Finances::getRetirement()
{
    return retirement;
}

QStringList Finances::getInvestmentSchemes()
{
    return investment_schemes;
}

QStringList Finances::getDebtsToYou()
{
    return debts_to_you;
}

QStringList Finances::getDebtsOwedByYou()
{
    return debts_owed_by_you;
}

QStringList Finances::getOverseasTravel()
{
    return overseas_travel;
}

QStringList Finances::getGifts()
{
    return gifts;
}

QStringList Finances::getPaymentActivities()
{
    return payment_activities;
}
