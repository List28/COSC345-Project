#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include "dialog.h"
#include "expandedcard.h"
#include <QDebug>
#include <QBoxLayout>
#include <dbmanager.h>

static const QString path = "parliament.db";

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
    DbManager db(path);
    std::vector<MP> mps;

    if (db.isOpen())
    {
        mps = db.getAllMps();
        if (!mps.empty()) 
        {
            showMpsOnScreen(mps);
        }
        else {
            qDebug() << "No mps found";
        }
    }
    else 
    {
        qDebug() << "Couldn't open mps";
    }    
}

void MainWindow::showMpsOnScreen(std::vector<MP> mps) {
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

void MainWindow::on_filterButton_clicked()
{
    QString searchQuery = ui->searchQuery->text();
    QString partyQuery = ui->partyQuery->currentText();
    qDebug() << searchQuery << " " << partyQuery;
    
    DbManager db(path);
    std::vector<MP> mps;

    if (db.isOpen())
    {
        if (partyQuery == "All") {
            mps = db.getAllMps();
        }
        else {
            mps = db.getAllMpsFromParty(partyQuery);
        }
        
        if (!mps.empty())
        {
            if (searchQuery.isEmpty()) {
                showMpsOnScreen(mps);
            }
            else {
                std::vector<MP> filteredMps;
                for (size_t i = 0; i < mps.size(); ++i) {
                    if (mps[i].getName().contains(searchQuery)) {
                        filteredMps.push_back(mps[i]);
                    }
                    else if (mps[i].getParty().contains(searchQuery)) {
                        filteredMps.push_back(mps[i]);
                    }
                    else if (mps[i].getElectorate().contains(searchQuery)) {
                        filteredMps.push_back(mps[i]);
                    }
                }

                showMpsOnScreen(filteredMps);
            }
            
        }
        else {
            qDebug() << "No mps found";
        }
    }
    else
    {
        qDebug() << "Couldn't open mps";
    }
}

