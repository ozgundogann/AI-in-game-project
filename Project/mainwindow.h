#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QTextBrowser>
#include "professions.h"
#include "properties.h"
#include "agent.h"


#define MAX 23

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Properties* person[20];
    Detective* agent;
    QVBoxLayout* box[20];
    QMessageBox* detectiveInfo;
    //QTextBrowser* listOfFounds;
    QTextBrowser* textBrowser;
    int personNumber;
    int killCount = 0;
    int x, check = 0;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_nextDayButton_clicked();
    void on_pNumButton_clicked();
    void winPixes();
};

#endif // MAINWINDOW_H
