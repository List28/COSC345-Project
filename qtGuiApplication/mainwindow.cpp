#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "dialog.h"
#include "expandedcard.h"
#include <QDebug>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    expandedCard = nullptr;
}

MainWindow::~MainWindow()
{
    clearCardsLayout();
    delete ui;
}

void MainWindow::handleExpandButtonClicked()
{
    Card *senderCard = qobject_cast<Card*>(sender());
    if (senderCard) {
        if (expandedCard) {
            delete expandedCard;
        }

        expandedCard = new ExpandedCard;
        ui->CardsLayout->addWidget(expandedCard);
        senderCard->hide();

        // Hide all existing cards
        for (Card *card : cards) {
            card->hide();
        }
    }
}


void MainWindow::handleOkButtonClicked()
{
    for (Card *card : cards) {
        card->show();
    }

    if (expandedCard) {
        ui->CardsLayout->removeWidget(expandedCard);
        delete expandedCard;
        expandedCard = nullptr;
    }
}

void MainWindow::on_peopleButton_clicked()
{
    clearCardsLayout();

    for (int var = 0; var < 5; ++var) {
        Card *card = new Card;
        ui->CardsLayout->addWidget(card);
        cards.push_back(card);

        connect(card, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
    }
}

void MainWindow::on_partiesButton_clicked()
{
    clearCardsLayout();

    Dialog *dialog = new Dialog;
    ui->CardsLayout->addWidget(dialog);
}

void MainWindow::clearCardsLayout()
{
    for (Card *card : cards) {
        disconnect(card, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
        card->hide();
        card->deleteLater();
    }
    cards.clear();

    if (expandedCard) {
        delete expandedCard;
        expandedCard = nullptr;
    }

    QLayoutItem *item;
    while ((item = ui->CardsLayout->takeAt(0)) != nullptr) {
        QWidget *widget = item->widget();
        if (widget) {
            delete widget;
        }
        delete item;
    }
}
