#ifndef EXPANDEDCARD_H
#define EXPANDEDCARD_H

#include <QDialog>
#include "mp.h"

namespace Ui {
class ExpandedCard;
}

class ExpandedCard : public QDialog
{
    Q_OBJECT

public:
    explicit ExpandedCard(QWidget *parent = nullptr);
    explicit ExpandedCard(MP mp);
    ~ExpandedCard();
private:
    Ui::ExpandedCard *ui;
    MP mp;
signals:
    void okButtonClicked(); // Add the signal for the "OK" button

private slots:
    void on_okButton_accepted();
};

#endif // EXPANDEDCARD_H
