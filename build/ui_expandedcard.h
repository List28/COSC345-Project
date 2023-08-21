/********************************************************************************
** Form generated from reading UI file 'expandedcard.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPANDEDCARD_H
#define UI_EXPANDEDCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpandedCard
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    QLabel *Party;
    QDialogButtonBox *okButton;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *Portrait;
    QWidget *widget_2;
    QVBoxLayout *expandedLayoutWindow;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QLabel *label_3;

    void setupUi(QDialog *ExpandedCard)
    {
        if (ExpandedCard->objectName().isEmpty())
            ExpandedCard->setObjectName("ExpandedCard");
        ExpandedCard->resize(1023, 469);
        gridLayout = new QGridLayout(ExpandedCard);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(ExpandedCard);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        Name = new QLabel(widget);
        Name->setObjectName("Name");
        Name->setMaximumSize(QSize(100, 30));

        verticalLayout->addWidget(Name);

        Party = new QLabel(widget);
        Party->setObjectName("Party");
        Party->setMaximumSize(QSize(170, 30));

        verticalLayout->addWidget(Party);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        okButton = new QDialogButtonBox(ExpandedCard);
        okButton->setObjectName("okButton");
        okButton->setMaximumSize(QSize(50, 30));
        okButton->setOrientation(Qt::Horizontal);
        okButton->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(okButton, 0, 2, 1, 1);

        frame = new QFrame(ExpandedCard);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(16777215, 60));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout->addWidget(pushButton_4);


        gridLayout->addWidget(frame, 6, 0, 1, 3);

        Portrait = new QLabel(ExpandedCard);
        Portrait->setObjectName("Portrait");
        Portrait->setMaximumSize(QSize(100, 100));
        Portrait->setFrameShape(QFrame::NoFrame);
        Portrait->setFrameShadow(QFrame::Plain);
        Portrait->setPixmap(QPixmap(QString::fromUtf8("../images/wood-michael-TEST.jpg")));
        Portrait->setScaledContents(true);

        gridLayout->addWidget(Portrait, 0, 0, 1, 1);

        widget_2 = new QWidget(ExpandedCard);
        widget_2->setObjectName("widget_2");
        expandedLayoutWindow = new QVBoxLayout(widget_2);
        expandedLayoutWindow->setObjectName("expandedLayoutWindow");
        verticalSpacer = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Maximum);

        expandedLayoutWindow->addItem(verticalSpacer);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");

        expandedLayoutWindow->addWidget(label_5);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");
        label_3->setWordWrap(true);

        expandedLayoutWindow->addWidget(label_3);


        gridLayout->addWidget(widget_2, 7, 0, 1, 3);


        retranslateUi(ExpandedCard);

        QMetaObject::connectSlotsByName(ExpandedCard);
    } // setupUi

    void retranslateUi(QDialog *ExpandedCard)
    {
        ExpandedCard->setWindowTitle(QCoreApplication::translate("ExpandedCard", "Dialog", nullptr));
        Name->setText(QCoreApplication::translate("ExpandedCard", "<html><head/><body><p><span style=\" font-weight:700;\">Michael wood</span></p></body></html>", nullptr));
        Party->setText(QCoreApplication::translate("ExpandedCard", "<html><head/><body><p><span style=\" font-weight:700;\">Labour MP for Mt Roskill</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("ExpandedCard", "Overview", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ExpandedCard", "Details", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ExpandedCard", "Interests", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ExpandedCard", "Expenses", nullptr));
        Portrait->setText(QString());
        label_5->setText(QCoreApplication::translate("ExpandedCard", "Transcript:", nullptr));
        label_3->setText(QCoreApplication::translate("ExpandedCard", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.Lorem ipsum dolor sit a"
                        "met, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nul pariatur.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExpandedCard: public Ui_ExpandedCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPANDEDCARD_H
