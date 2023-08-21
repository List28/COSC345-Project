#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector> // Include the <vector> header

// Include necessary headers for your classes here
#include "card.h"
#include "expandedcard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Card*> cards; // Use std::vector for managing Card pointers
    ExpandedCard *expandedCard; // Declare expandedCard here
    QMap<Card*, ExpandedCard*> expandedCardsMap;

private slots:
    void handleExpandButtonClicked();
    void handleOkButtonClicked();
    void on_peopleButton_clicked();
    void on_partiesButton_clicked();
    void clearCardsLayout();
    void on_filterButton_clicked();
};

#endif // MAINWINDOW_H
