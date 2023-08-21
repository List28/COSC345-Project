#include "card.h"
#include "ui_card.h"
#include "expandedcard.h"
#include "mainwindow.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QPushButton>

#include "mp.h"

Card::Card(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Card)
{
   
    ui->setupUi(this);
}

Card::Card(MP mp) :
    ui(new Ui::Card)
{
    this->mp = mp;

    ui->setupUi(this);
    ui->Name->setText(mp.getName());
    ui->Party->setText(mp.getParty());

    ui->Portrait->setPixmap(QPixmap("../images/portraits/" + mp.getName() + ".jpg"));
}

Card::~Card()
{
    delete ui;
}

// just to draw a border. could also use stylesheet
void Card::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawRect(0,0,width()-1, height()-1);

}


void Card::on_expandButton_clicked()
{
    emit expandButtonClicked(mp);
}
