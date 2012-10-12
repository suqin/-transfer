///////////////////////////////////////////////////////////
//  ChatData.h
//  Implementation of the Class ChatData
//  Created on:      06-Ò»ÔÂ-2012 23:13:45
//  Original author: GA
///////////////////////////////////////////////////////////

#ifndef ChatData_h
#define ChatData_h

#include "Data.h"

class ChatData : public Data
{

public:
        ChatData(IPInfomation *goal,QString time);
        QString OutPutBuff();
        void AddInfomationFromBuff(QString str);
	virtual ~ChatData();
        QString getTime(){return Time;}
        qint16 GetPort();
        QString GetIP();
	qint64 GetSize();

private:
        QString Time;
        IPInfomation *goalIPInfomation;
	qint64 size;
	QString Buff;

};
#endif // ChatData.h
