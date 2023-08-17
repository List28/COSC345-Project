#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include "mp.h"

namespace Ui {
class Card;
}

class Card : public QWidget
{
    Q_OBJECT

public:
    explicit Card(QWidget *parent = nullptr);
    Card(MP mp);
    ~Card();
signals:
    void expandButtonClicked();
private slots:
    void on_expandButton_clicked();
private:
    Ui::Card *ui;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};

#endif // CARD_H
