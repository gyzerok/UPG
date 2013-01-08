#ifndef QSERVERSIDE_H
#define QSERVERSIDE_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QDebug>

class QServerSide : public QTcpServer
{
    Q_OBJECT
public:
    explicit QServerSide(QObject *parent = 0);
    void incomingConnection(int handle);

signals:
    void requestReceived(QObject* socket, QString request);
    void clientDisconnected(QObject* socket);

public slots:
    void onReadyRead();
    void onResponseReady(QList<QObject*> socket, QString response);
    void onDisconnected();
};

#endif // SERVERSIDE_H
