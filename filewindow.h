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
    void send();  //���ӷ�����
    void startTransfer();  //�����ļ���С����Ϣ
    void updateClientProgress(qint64); //�������ݣ����½�����
    //void displayError(QAbstractSocket::SocketError); //��ʾ����
    void acceptConnection();//����������
    void updateServerProgress();  //���½���������������
private:
    Ui::FileWindow *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    QTcpSocket *reciver;
    QString fileName;
    qint64 fileNameSize;
    QFile *file;
    qint64 totalBytes;  //�����ܴ�С
    qint64 bytesWritten;  //�Ѿ��������ݴ�С
    qint64 bytesToWrite;   //ʣ�����ݴ�С
    qint64 loadSize;   //ÿ�η������ݵĴ�С
    QByteArray Block;  //���ݻ�����
    int recived;
};

#endif // FILEWINDOW_H
