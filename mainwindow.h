#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include <QDateTime>

#include "Reciver.h"
#include "Sender.h"
#include "ChatData.h"
#include "IPInfomation.h"
#include "filewindow.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString GetTime();
    QString GetMyIP();
    ~MainWindow();
public slots:
    void sendMsg();
    void getMsg();
    void hideWindow();
    void showWindow();
   // void sendFile();
  //  void getFile();
private:
    QString news;
    Ui::MainWindow *ui;
    Sender *sender;
    Reciver *reciver;
   // Reciver *server;
    FileWindow *f;


};

#endif // MAINWINDOW_H
