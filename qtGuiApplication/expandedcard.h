#ifndef EXPANDEDCARD_H
#define EXPANDEDCARD_H

#include <QDialog>

namespace Ui {
class ExpandedCard;
}

class ExpandedCard : public QDialog
{
    Q_OBJECT

public:
    explicit ExpandedCard(QWidget *parent = nullptr);
    ~ExpandedCard();
private:
    Ui::ExpandedCard *ui;
signals:
    void okButtonClicked(); // Add the signal for the "OK" button

private slots:
    void on_okButton_accepted();
};

#endif // EXPANDEDCARD_H
