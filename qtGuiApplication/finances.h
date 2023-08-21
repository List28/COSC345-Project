#ifndef Finances_H
#define Finances_H

#include <QString>
#include <QStringList>

class Finances
{
public:
    Finances();
    Finances(const QString mp_name, const QStringList company_directorships,
        const QStringList other_companies, const QStringList employment, const QStringList interest_trust,
        const QStringList organizations, const QStringList property, const QStringList retirement,
        const QStringList investment_schemes, const QStringList debts_to_you, const QStringList debts_owed_by_you,
        const QStringList overseas_travel, const QStringList gifts, const QStringList payment_activities);

    QString getMpName() const;
    QStringList getCompanyDirectorships() const;
    QStringList getOtherCompanies();
    QStringList getEmployment();
    QStringList getInterestTrust();
    QStringList getOrganizations();
    QStringList getProperty();
    QStringList getRetirement();
    QStringList getInvestmentSchemes();
    QStringList getDebtsToYou();
    QStringList getDebtsOwedByYou();
    QStringList getOverseasTravel();
    QStringList getGifts();
    QStringList getPaymentActivities();

private:
    QString mp_name;
    QStringList employment;
    QStringList company_directorships;
    QStringList other_companies;
    QStringList interest_trust;
    QStringList organizations;
    QStringList property;
    QStringList retirement;
    QStringList investment_schemes;
    QStringList debts_to_you;
    QStringList debts_owed_by_you;
    QStringList overseas_travel;
    QStringList gifts;
    QStringList payment_activities;
};

#endif // MP_H