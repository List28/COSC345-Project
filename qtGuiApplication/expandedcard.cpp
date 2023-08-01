#include "expandedcard.h"
#include "ui_expandedcard.h"
#include <QDialogButtonBox>

ExpandedCard::ExpandedCard(QWidget *parent) : QDialog(parent), ui(new Ui::ExpandedCard)
{
    ui->setupUi(this);

    // Assuming the QDialogButtonBox in the UI file is named 'okButton'
    connect(ui->okButton, &QDialogButtonBox::accepted, this, &ExpandedCard::on_okButton_accepted);
    connect(ui->okButton, &QDialogButtonBox::rejected, this, &ExpandedCard::deleteLater);
}
ExpandedCard::~ExpandedCard()
{
    delete ui;
}

void ExpandedCard::on_okButton_accepted()
{
    qDebug() << "OK Button Accepted"; // Debug message
    // Emit the custom signal okButtonClicked() when the "OK" button is clicked
    emit okButtonClicked();
}

