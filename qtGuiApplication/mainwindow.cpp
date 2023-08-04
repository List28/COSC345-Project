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
    , expandedCardIndex(-1)
{
    ui->setupUi(this);

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

        // If there is a previously expanded card, restore it in the layout
        if (expandedCardIndex != -1) {
            // Get the index of the senderCard in the layout
            int senderCardIndex = ui->CardsLayout->indexOf(senderCard);

            // Remove the senderCard from the layout and insert the expandedCard at its position
            ui->CardsLayout->removeWidget(senderCard);
            ui->CardsLayout->insertWidget(senderCardIndex, expandedCard);

            // Disconnect the signal of the senderCard to avoid duplicated signals
            disconnect(senderCard, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);

            // If the index of the expanded card is greater than the index of the previously expanded card,
            // adjust the expandedCardIndex by decrementing it by 1 to reflect the change in layout.
            if (senderCardIndex < expandedCardIndex) {
                expandedCardIndex--;
            }
        }

        // Remove the senderCard from the vector using std::remove_if with lambda expression
        cards.erase(std::remove_if(cards.begin(), cards.end(),
                                   [senderCard](Card *c) { return c == senderCard; }),
                    cards.end());

        // Find the index of the senderCard and store it as the expandedCardIndex
        expandedCardIndex = ui->CardsLayout->indexOf(senderCard);

        senderCard->deleteLater(); // Delete the Card instance, assuming it's no longer needed

        // Assuming you have a layout for ExpandedCard, insert it in place of the senderCard
        ui->CardsLayout->insertWidget(expandedCardIndex, expandedCard);

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
        // Get the index where the expandedCard will be inserted back in the layout
        int index = expandedCardIndex;

        // Assuming you have a layout for Card, add it back to the vector and insert it back into the layout
        Card *card = new Card;
        ui->CardsLayout->insertWidget(index, card);
        cards.insert(cards.begin() + index, card);

        disconnect(expandedCard, &ExpandedCard::okButtonClicked, this, &MainWindow::handleOkButtonClicked); // Disconnect the signal

        expandedCard->deleteLater(); // Delete the ExpandedCard instance

        // Reset the expandedCardIndex to an invalid value, indicating no card is currently expanded
        expandedCardIndex = -1;

        // Connect the signal of the new card to the slot for expanding
        connect(card, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
    }
}

void MainWindow::on_peopleButton_clicked()
{
    for (int var = 0; var < 5; ++var) {
        Card *card = new Card;
        ui->CardsLayout->addWidget(card);
        cards.push_back(card); // Store the pointers to Card instances

        // Connect the signal from each Card instance to the MainWindow slot
        connect(card, &Card::expandButtonClicked, this, &MainWindow::handleExpandButtonClicked);
    }
}

