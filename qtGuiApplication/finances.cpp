#include "finances.h"

Finances::Finances(const QString mp_name, std::vector<QString>& company_directorships, 
    std::vector<QString>& other_companies, std::vector<QString>& employment,
    std::vector<QString>& interest_trust, std::vector<QString>& organizations,
    std::vector<QString>& property, std::vector<QString>& retirement, 
    std::vector<QString>&  investment_schemes, std::vector<QString>& debts_to_you,
    std::vector<QString>& debts_owed_by_you, std::vector<QString>& overseas_travel,
    std::vector<QString>& gifts, std::vector<QString>& payment_activities) :
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

std::vector<QString>& Finances::getCompanyDirectorships()
{
    return company_directorships;
}

std::vector<QString>& Finances::getOtherCompanies()
{
    return other_companies;
}

std::vector<QString>& Finances::getEmployment()
{
    return employment;
}

std::vector<QString>& Finances::getInterestTrust()
{
    return interest_trust;
}

std::vector<QString>& Finances::getOrganizations()
{
    return organizations;
}

std::vector<QString>& Finances::getProperty()
{
    return property;
}

std::vector<QString>& Finances::getRetirement()
{
    return retirement;
}

std::vector<QString>& Finances::getInvestmentSchemes()
{
    return investment_schemes;
}

std::vector<QString>& Finances::getDebtsToYou()
{
    return debts_to_you;
}

std::vector<QString>& Finances::getDebtsOwedByYou()
{
    return debts_owed_by_you;
}

std::vector<QString>& Finances::getOverseasTravel()
{
    return overseas_travel;
}

std::vector<QString>& Finances::getGifts()
{
    return gifts;
}

std::vector<QString>& Finances::getPaymentActivities()
{
    return payment_activities;
}
