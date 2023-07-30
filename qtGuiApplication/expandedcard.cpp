#include "expandedcard.h"
#include "ui_expandedcard.h"

ExpandedCard::ExpandedCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpandedCard)
{
    ui->setupUi(this);
}

ExpandedCard::~ExpandedCard()
{
    delete ui;
}
