#include "filewindow.h"
#include "ui_filewindow.h"

FileWindow::FileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileWindow)
{
    ui->setupUi(this);
    server = new QTcpServer();
    socket = new QTcpSocket();
    fileNameSize=0;
    totalBytes=0; //�����ܴ�С
    bytesWritten=0;  //�Ѿ��������ݴ�С
  bytesToWrite=0;   //ʣ�����ݴ�С
    loadSize=4096;   //ÿ�η������ݵĴ�С
    recived=0;
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);
    server->listen(QHostAddress::Any,6666);
    connect(server,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
    connect(ui->openButton_2,SIGNAL(clicked()),this,SLOT(openfile()));
    connect(ui->sendButton,SIGNAL(clicked()),this,SLOT(send()));
    connect(socket,SIGNAL(connected()),this,SLOT(startTransfer()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(updateClientProgress(qint64)));
    connect(ui->returnButton_3,SIGNAL(clicked()),this,SLOT(close()));
}
void FileWindow::acceptConnection()
{
    ui->label_2->setText(tr("�ļ�������"));
    reciver=server->nextPendingConnection();
    connect(reciver,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    server->close();
}
void FileWindow::updateServerProgress()
{
    QDataStream in(reciver);
    in.setVersion(QDataStream::Qt_4_7);
    if(recived==0)
    {
        in >> totalBytes >> fileNameSize;
        recived += sizeof(qint64) * 2;
        in >> fileName;
        recived += fileNameSize;
        file=new QFile(fileName);//
        if(!file->open(QFile::WriteOnly)) exit(2);
    }
    else if(recived < totalBytes)
    {
        recived+=reciver->bytesAvailable();
        Block.resize(0);
        Block=reciver->readAll();
        file->write(Block);
        Block.resize(0);
    }
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(recived);
    if(recived==totalBytes)
    {
        _init();
        ui->label_2->setText(tr("�������"));
        delete reciver;
    }
}
void FileWindow::_init()
{
    server->listen(QHostAddress::Any,6666);
    //delete reciver;
    fileName="";
    fileNameSize=0;
    delete file;
    totalBytes=0; //�����ܴ�С
    bytesWritten=0;  //�Ѿ��������ݴ�С
  bytesToWrite=0;   //ʣ�����ݴ�С
    loadSize=4096;   //ÿ�η������ݵĴ�С
    recived=0;
}

void FileWindow::openfile()
{
    fileName = QFileDialog::getOpenFileName(this);
        if(!fileName.isEmpty())
        {
            ui->sendButton->setEnabled(true);
            ui->label->setText(tr("���ļ� %1 �ɹ���") .arg(fileName));
        }
}
void FileWindow::send()
{
    socket->connectToHost(ui->lineEdit->text(),6666);
    ui->label_2->setText(tr("������......"));
    ui->openButton_2->setEnabled(0);
     bytesWritten = 0;
}
void FileWindow::startTransfer()
{
    file=new QFile(fileName);
    if(!file->open(QFile::ReadOnly)) exit(1);
    totalBytes=file->size();
    QDataStream sendOut(&Block,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_7);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
     sendOut << qint64(0) << qint64(0) << currentFileName;
     totalBytes += Block.size();
     sendOut.device()->seek(0);
     sendOut<<totalBytes<<qint64((Block.size() - sizeof(qint64)*2));
     bytesToWrite = totalBytes - socket->write(Block);
    ui->label_2->setText(tr("������"));
     Block.resize(0);
     ui->sendButton->setEnabled(false);
}
void FileWindow::updateClientProgress(qint64 numBytes)
{
    bytesWritten+=numBytes;
    if(bytesToWrite>0)
    {
        Block = file->read(qMin(bytesToWrite,loadSize));

         bytesToWrite -= (int)socket->write(Block);
         Block.resize(0);
    }
    else
    {
        file->close();
        ui->label_2->setText("fuck");
    }
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesWritten);
//���½�����
  if(bytesWritten == totalBytes) //�������
    {
        ui->label_2->setText(tr("�����ļ� %1 �ɹ�").arg(fileName));
        file->close();
        socket->close();
        ui->sendButton->setEnabled(1);
        ui->openButton_2->setEnabled(1);
        _init();
    }
}
////////////////////////////////////////////////
//
//���ղ���
//
///////////////////////////////////////////////

FileWindow::~FileWindow()
{
    server->close();
    delete server;
    delete ui;
}
