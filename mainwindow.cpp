#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_3->setText(GetMyIP());
    ui->displayEdit->setReadOnly(1);
    sender=new MsgSender();
    reciver=new MsgReciver();
    reciver->listenTo(6667);
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(sendMsg()));
    connect(reciver->getReciver(),SIGNAL(readyRead()),this,SLOT(getMsg()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showWindow()));
 //   f=new FileWindow(this);
  //  f->show();
}
void MainWindow::showWindow()
{
    f=new FileWindow(this);
    f->show();
    ui->pushButton->disconnect();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hideWindow()));
}
void MainWindow::hideWindow()
{
    f->close();
    delete f;
    ui->pushButton->disconnect();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(showWindow()));
}
void MainWindow::getMsg()
{

    Data *data;
    data=reciver->getData();
    news+=data->GetIP();
    news+="   @   ";
    news+=GetTime();
    news+="     say:\n";
    news+=data->OutPutBuff();
    news+="\n";
    ui->displayEdit->setPlainText(QObject::tr(news.toAscii()));
}

void MainWindow::sendMsg()
{
    qint16 po;
    IPInfomation *goalIp;
    po=6667;
    goalIp=new IPInfomation(ui->IpEdit->text(),po);
    QString time=GetTime();
    ChatData *msg;
    msg=new ChatData(goalIp,time);
    msg->AddInfomationFromBuff(ui->msgEdit->text().toLocal8Bit());
    sender->Send(msg);
    news+=ui->IpEdit->text();
    news+="    @    ";
    news+=time;
    news+="say:\n";
    news+=msg->OutPutBuff();
    news+="\n";
     ui->displayEdit->setPlainText(QObject::tr(news.toAscii()));
     ui->msgEdit->clear();

}
QString MainWindow::GetTime()// d得到当前时间信息
{
    QDateTime time;
    time=QDateTime::currentDateTime();
    return time.toString("hh:mm:ss");
}
QString MainWindow::GetMyIP()
{
    QString ipAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
                ipAddress = ipAddressesList.at(i).toString();
                break;
            }
        }
        if (ipAddress.isEmpty())
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
       return ipAddress;
}

MainWindow::~MainWindow()
{
    delete ui;
}
