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

};

#endif // EXPANDEDCARD_H
