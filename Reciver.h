///////////////////////////////////////////////////////////
//  Reciver.h
//  Implementation of the Class Reciver
//  Created on:      06-一月-2012 23:11:03
//  Original author: GA
///////////////////////////////////////////////////////////

#ifndef Reciver_h
#define Reciver_h
#include <QUdpSocket>
#include <QtNetwork>
#include <QString>
#include <QObject>
#include <QFileDialog>
#include "ChatData.h"
class Reciver: public QObject
{
    Q_OBJECT
public:
    virtual Data *getData()=0;
    virtual QAbstractSocket *getReciver()=0;
    virtual void listenTo(qint16 Port)=0;
};
class MsgReciver :public Reciver
{
    Q_OBJECT
public:
        MsgReciver();
        virtual ~MsgReciver();
        QAbstractSocket *getReciver(){return reciver;}
        void listenTo(qint16 Port);
        Data *getData();
private:
        QUdpSocket * reciver;
};
#endif // !Reciver_h
