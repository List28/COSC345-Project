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

        senderCard->deleteLater(); // Delete the Card instance, assuming it's no longer needed

        // Assuming you have a layout for ExpandedCard, add it to the layout
        ui->CardsLayout->addWidget(expandedCard);

        // If the layout needs to be resized after adding the ExpandedCard, you can call
        // ui->CardsLayout->update(); or ui->CardsLayout->activate();
    }
}
