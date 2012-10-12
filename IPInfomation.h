///////////////////////////////////////////////////////////
//  IPInfomation.h
//  Implementation of the Class IPInfomation
//  Created on:      06-Ò»ÔÂ-2012 22:47:13
//  Original author: GA
///////////////////////////////////////////////////////////

#ifndef IPInfomation_h
#define IPInfomation_h
#include <QString>
#include <QtNetwork>
class IPInfomation
{

public:
	IPInfomation();
	virtual ~IPInfomation();

        IPInfomation(qint16 port);
        IPInfomation(QString IP, qint16 Port);
        qint16 GetPort();
	QString GetIP();

private:
	QString IP;
        qint16 port;

};
#endif // IPInfomation.h
