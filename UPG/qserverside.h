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
    void requestReceived(void* socket, QString request);

public slots:
    void onReadyRead();
    void onResponseReady(QList<void*> socket, QString response);
    void onDisconnected();

private:
    QMap<int, QTcpSocket*>      m_clients;
};

#endif // SERVERSIDE_H
