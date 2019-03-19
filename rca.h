#ifndef RCA_H
#define RCA_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QSet>
#include <QMap>
#include <QPair>
#include <QString>
#include <QSharedPointer>
#include "wcu.h"
#include "wplanner.h"
#include "w3dscene.h"



class Rca: public QTcpServer
{
    Q_OBJECT

public:
    Rca();
    Rca(W3dscene s);
    ~Rca();
    Rca(const Rca&) = delete;
    Rca& operator=(const Rca&) = delete;
    Rca(Rca&&)  = delete;
    Rca& operator=(Rca&&) = delete;
private:
    QTcpSocket* socket;
    QTcpSocket* newsocket;
    W3dscene scene;
    Wplanner planner;
    QSet<QTcpSocket*> socketNobody;
    QMap<QByteArray,Wcu> units;
public slots:

    void incomingConnection(int socketDescriptor);
    void disperser(QByteArray n1,QByteArray n2);
    void sockReady();
    void sockDisc();

};

#endif // RCA_H
