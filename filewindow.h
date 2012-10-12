#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QFileDialog>
#include <QtNetwork>
namespace Ui {
    class FileWindow;
}

class FileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileWindow(QWidget *parent = 0);
    ~FileWindow();
    void _init();
public slots:
    void openfile();
    void send();  //连接服务器
    void startTransfer();  //发送文件大小等信息
    void updateClientProgress(qint64); //发送数据，更新进度条
    //void displayError(QAbstractSocket::SocketError); //显示错误
    void acceptConnection();//建立新链接
    void updateServerProgress();  //更新进度条，接收数据
private:
    Ui::FileWindow *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    QTcpSocket *reciver;
    QString fileName;
    qint64 fileNameSize;
    QFile *file;
    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;   //每次发送数据的大小
    QByteArray Block;  //数据缓冲区
    int recived;
};

#endif // FILEWINDOW_H
