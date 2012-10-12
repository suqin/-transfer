///////////////////////////////////////////////////////////
//  ChatData.cpp
//  Implementation of the Class ChatData
//  Created on:      06-Ò»ÔÂ-2012 23:13:45
//  Original author: GA
///////////////////////////////////////////////////////////

#include "ChatData.h"


ChatData::ChatData(IPInfomation *goal,QString time)
{
    goalIPInfomation = goal;
    Time+=time;
}
ChatData::~ChatData()
{

}
QString ChatData::OutPutBuff()
{
        return  Buff;
}
QString ChatData::GetIP()
{
    return goalIPInfomation->GetIP();
}
qint16 ChatData::GetPort()
{
    return goalIPInfomation->GetPort();
}

void ChatData::AddInfomationFromBuff(QString str)
{
        Buff=str;
        size=(qint64)(sizeof(Buff));
}
qint64 ChatData::GetSize(){

        return  size;
}
