///////////////////////////////////////////////////////////
//  Reciver.cpp
//  Implementation of the Class Reciver
//  Created on:      06-一月-2012 23:11:03
//  Original author: GA
///////////////////////////////////////////////////////////

#include "Reciver.h"


MsgReciver::MsgReciver()
{
    reciver=new QUdpSocket();
}
MsgReciver::~MsgReciver()
{

}
void MsgReciver::listenTo(qint16 Port)
{
      reciver->bind(Port);
}
Data *MsgReciver::getData()
{
    QString str;
    QHostAddress address;
    quint16 port;
    QByteArray dataGrams;
    int size=0;
    while(reciver->hasPendingDatagrams())
    {
        size=reciver->pendingDatagramSize();
        dataGrams.resize(size);
        reciver->readDatagram(dataGrams.data(),dataGrams.size(),&address,&port);
    }
    IPInfomation *goalInfo;//外部IP信息
    goalInfo=new IPInfomation(address.toString(),port);
    QString Buff;
    QDateTime time;
    time=QDateTime::currentDateTime();
    ChatData *data;
    data=new ChatData(goalInfo,time.toString("hh:mm:ss"));
    Buff=Buff.fromAscii(dataGrams.data());
    data->AddInfomationFromBuff(Buff);
    return data;
}
