#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "dialog.h"
#include "expandedcard.h"
#include <QDebug>
#include <QBoxLayout>
#include <dbmanager.h>

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

void MainWindow::handleExpandButtonClicked(MP mp)
{
    Card *senderCard = qobject_cast<Card*>(sender());
    if (senderCard) {
        if (expandedCard) {
            delete expandedCard;
        }

        expandedCard = new ExpandedCard(mp);
        connect(expandedCard, &ExpandedCard::okButtonClicked, this, &MainWindow::handleOkButtonClicked);
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
    static const QString path = "parliament.db";
    DbManager db(path);
    std::vector<MP> mps;

    if (db.isOpen())
    {
        mps = db.getAllMps();
    }

    clearCardsLayout();

    int maxColumns = 3; // Maximum number of cards per row
    int currentColumn = 0;
    int currentRow = 0;

    for (size_t i = 0; i < mps.size(); ++i) {
        Card* card = new Card(mps[i]);
        ui->CardsLayout->addWidget(card, currentRow, currentColumn);

        // Update column and row positions
        ++currentColumn;
        if (currentColumn >= maxColumns) {
            currentColumn = 0;
            ++currentRow;
        }

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
