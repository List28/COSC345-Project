/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Card
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Portrait;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *Name;
    QLabel *Party;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *expandButton;

    void setupUi(QWidget *Card)
    {
        if (Card->objectName().isEmpty())
            Card->setObjectName("Card");
        Card->resize(219, 150);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Card->sizePolicy().hasHeightForWidth());
        Card->setSizePolicy(sizePolicy);
        Card->setMaximumSize(QSize(219, 150));
        verticalLayout = new QVBoxLayout(Card);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Portrait = new QLabel(Card);
        Portrait->setObjectName("Portrait");
        Portrait->setMaximumSize(QSize(64, 64));
        Portrait->setFrameShadow(QFrame::Plain);
        Portrait->setPixmap(QPixmap(QString::fromUtf8("../images/wood-michael-TEST.jpg")));
        Portrait->setScaledContents(true);

        horizontalLayout->addWidget(Portrait);

        frame = new QFrame(Card);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        Name = new QLabel(frame);
        Name->setObjectName("Name");

        verticalLayout_2->addWidget(Name);

        Party = new QLabel(frame);
        Party->setObjectName("Party");

        verticalLayout_2->addWidget(Party);


        horizontalLayout->addWidget(frame);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        expandButton = new QPushButton(Card);
        expandButton->setObjectName("expandButton");
        expandButton->setFlat(false);

        horizontalLayout_3->addWidget(expandButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Card);
        QObject::connect(expandButton, &QPushButton::clicked, Card, qOverload<>(&QWidget::show));

        expandButton->setDefault(true);


        QMetaObject::connectSlotsByName(Card);
    } // setupUi

    void retranslateUi(QWidget *Card)
    {
        Card->setWindowTitle(QCoreApplication::translate("Card", "Form", nullptr));
        Portrait->setText(QString());
        Name->setText(QCoreApplication::translate("Card", "Michael Woodhouse", nullptr));
        Party->setText(QCoreApplication::translate("Card", "Labour", nullptr));
        expandButton->setText(QCoreApplication::translate("Card", "Expand", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Card: public Ui_Card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H
