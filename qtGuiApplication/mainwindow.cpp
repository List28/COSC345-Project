#include "card.h"
#include "expandedcard.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int var = 0; var < 5; ++var) {
        Card *card = new Card;
        ui->CardsLayout->addWidget(card);
        cards.push_back(card); // Store the pointers to Card instances

        // Connect the signal from each Card instance to the MainWindow slot
        connect(card, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleExpandButtonClicked()
{
    Card *senderCard = qobject_cast<Card*>(sender());
    if (senderCard) {
        ExpandedCard *expandedCard = new ExpandedCard;
        ui->CardsLayout->replaceWidget(senderCard, expandedCard);
        ui->CardsLayout->removeWidget(senderCard);

        // Remove the senderCard from the vector using std::remove_if with lambda expression
        cards.erase(std::remove_if(cards.begin(), cards.end(),
                                   [senderCard](Card *c) { return c == senderCard; }),
                    cards.end());

        // Disconnect the Card's signal since it's being replaced by an ExpandedCard
        disconnect(senderCard, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
        senderCard->deleteLater(); // Delete the Card instance, assuming it's no longer needed

        // Assuming you have a layout for ExpandedCard, insert it at the top of the layout
        ui->CardsLayout->insertWidget(0, expandedCard);

        // If the layout needs to be resized after adding the ExpandedCard, you can call
        // ui->CardsLayout->update(); or ui->CardsLayout->activate();

        // Connect the okButtonClicked() signal from ExpandedCard to the slot handleOkButtonClicked() in MainWindow
        connect(expandedCard, &ExpandedCard::okButtonClicked, this, &MainWindow::handleOkButtonClicked);
    }
}


void MainWindow::handleOkButtonClicked()
{
    ExpandedCard *expandedCard = qobject_cast<ExpandedCard*>(sender());
    if (expandedCard) {
        ui->CardsLayout->removeWidget(expandedCard); // Remove the ExpandedCard from the layout
        disconnect(expandedCard, &ExpandedCard::okButtonClicked, this, &MainWindow::handleOkButtonClicked); // Disconnect the signal

        int index = 0; // Insert the Card back at the top
        Card *card = new Card;
        ui->CardsLayout->insertWidget(index, card);
        cards.insert(cards.begin(), card);

        expandedCard->deleteLater(); // Delete the ExpandedCard instance
    }
}
