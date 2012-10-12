///////////////////////////////////////////////////////////
//  Sender.cpp
//  Implementation of the Class Sender
//  Created on:      06-Ò»ÔÂ-2012 23:17:31
//  Original author: GA
///////////////////////////////////////////////////////////

#include "Sender.h"


MsgSender::MsgSender()
{
    sender=new QUdpSocket();
}
MsgSender::~MsgSender()
{
    delete sender;
}
int MsgSender::Send(Data *data)
{
   QHostAddress *address;
   address=new QHostAddress(data->GetIP());
    int n;
    n=sender->writeDatagram((data->OutPutBuff().toAscii()),*address,data->GetPort());
   return n;
}
