///////////////////////////////////////////////////////////
//  IPInfomation.cpp
//  Implementation of the Class IPInfomation
//  Created on:      06-Ò»ÔÂ-2012 22:47:13
//  Original author: GA
///////////////////////////////////////////////////////////

#include "IPInfomation.h"
IPInfomation::~IPInfomation()
{

}
IPInfomation::IPInfomation(qint16 port1)
{
    QString ipAddress;
        QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
                ipAddress = ipAddressesList.at(i).toString();
                break;
            }
        }
        if (ipAddress.isEmpty())
            ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
       IP=ipAddress;
       port=port1;

}


IPInfomation::IPInfomation(QString IP1,qint16 Port1)
{
    IP=IP1;
    port=Port1;

}


qint16 IPInfomation::GetPort(){

        return port;
}


QString IPInfomation::GetIP(){

        return  IP;
}
