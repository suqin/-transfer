///////////////////////////////////////////////////////////
//  Data.h
//  Implementation of the Class Data
//  Created on:      06-一月-2012 23:17:28
//  Original author: GA
///////////////////////////////////////////////////////////

#ifndef Data_h
#define Data_h

#include <QString>

#include "IPInfomation.h"

class Data
{
public:
        virtual void AddInfomationFromBuff(QString str)=0;
        virtual QString OutPutBuff()=0;
        virtual QString getTime()=0;
        virtual qint16 GetPort()=0;
        virtual QString GetIP()=0;
        virtual qint64 GetSize()=0;
};
#endif //Data.h
