// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector> // Include the <vector> header

// Include other necessary headers for your classes here
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
    std::vector<Card*> cards;

private slots:
    void handleExpandButtonClicked();
};
#endif // MAINWINDOW_H
