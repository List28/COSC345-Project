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
        ExpandedCard *expandedCard = new ExpandedCard;

        // ... (rest of the code as before)

        connect(expandedCard, &ExpandedCard::okButtonClicked, this, &MainWindow::handleOkButtonClicked);
        disconnect(senderCard, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
        senderCard->hide(); // Hide the sender card
        expandedCard->show(); // Show the expanded card
    }
}

void MainWindow::handleOkButtonClicked()
{
    ExpandedCard *expandedCard = qobject_cast<ExpandedCard*>(sender());
    if (expandedCard) {
        Card *senderCard = expandedCardsMap.key(expandedCard);

        if (senderCard) {
            int expandedCardIndex = ui->CardsLayout->indexOf(expandedCard);

            // Disconnect the signals from the expanded card
            disconnect(expandedCard, &ExpandedCard::okButtonClicked, this, &MainWindow::handleOkButtonClicked);
            expandedCard->hide(); // Hide the expanded card

            // Remove the expanded card from the layout
            ui->CardsLayout->removeWidget(expandedCard);
            expandedCard->deleteLater();

            // Insert the sender card back into the layout
            ui->CardsLayout->insertWidget(expandedCardIndex, senderCard);

            // Restore the signal-slot connection for expanding the card
            connect(senderCard, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
        }
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
        card->hide(); // Hide the card before deleting
        card->deleteLater();
    }
    cards.clear();

    QLayoutItem *item;
    while ((item = ui->CardsLayout->takeAt(0)) != nullptr) {
        QWidget *widget = item->widget();
        if (widget) {
            delete widget;
        }
        delete item;
    }

    expandedCardsMap.clear();
}
