#ifndef MP_H
#define MP_H

#include <QString>

class Finances
{
public:
    Finances(const QString mp_name, std::vector<QString>& company_directorships,
        std::vector<QString>& other_companies, std::vector<QString>& employment,
        std::vector<QString>& interest_trust, std::vector<QString>& organizations,
        std::vector<QString>& property, std::vector<QString>& retirement,
        std::vector<QString>& investment_schemes, std::vector<QString>& debts_to_you,
        std::vector<QString>& debts_owed_by_you, std::vector<QString>& overseas_travel,
        std::vector<QString>& gifts, std::vector<QString>& payment_activities);

    QString getMpName() const;
    std::vector<QString>& getCompanyDirectorships();
    std::vector<QString>& getOtherCompanies();
    std::vector<QString>& getEmployment();
    std::vector<QString>& getInterestTrust();
    std::vector<QString>& getOrganizations();
    std::vector<QString>& getProperty();
    std::vector<QString>& getRetirement();
    std::vector<QString>& getInvestmentSchemes();
    std::vector<QString>& getDebtsToYou();
    std::vector<QString>& getDebtsOwedByYou();
    std::vector<QString>& getOverseasTravel();
    std::vector<QString>& getGifts();
    std::vector<QString>& getPaymentActivities();

private:
    QString mp_name;
    std::vector<QString>& employment;
    std::vector<QString>& company_directorships;
    std::vector<QString>& other_companies;
    std::vector<QString>& interest_trust;
    std::vector<QString>& organizations;
    std::vector<QString>& property;
    std::vector<QString>& retirement;
    std::vector<QString>& investment_schemes;
    std::vector<QString>& debts_to_you;
    std::vector<QString>& debts_owed_by_you;
    std::vector<QString>& overseas_travel;
    std::vector<QString>& gifts;
    std::vector<QString>& payment_activities;
};

#endif // MP_H