///////////////////////////////////////////////////////////
//  Sender.h
//  Implementation of the Class Sender
//  Created on:      06-一月-2012 23:17:31
//  Original author: GA
///////////////////////////////////////////////////////////

#ifndef Sender_h
#define Sender_h
#include <QUdpSocket>
#include <QtNetwork>
#include <QString>
#include "ChatData.h"
#include <QHostAddress>
class Sender
{
public:
    virtual int Send(Data *data)=0;
};
class MsgSender :public Sender
{
public:
        MsgSender();
        virtual ~MsgSender();
        int Send(Data *data);
private:
        QUdpSocket * sender;
};
#endif // !Sender.h
