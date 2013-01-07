#include "QServerSide.h"

QServerSide::QServerSide(QObject *parent) :
    QTcpServer(parent)
{
    if (listen(QHostAddress::Any, 33333))
        qDebug() << "Listening...";
    else
        qDebug() << "Error while starting: " << errorString();
}

void QServerSide::incomingConnection(int handle)
{
    QTcpSocket* socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);

    //int socketID = socket->socketDescriptor();
    //m_clients[socketID] = socket;

    qDebug() << "New client connected. Socket id:" << socket->socketDescriptor();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

void QServerSide::onReadyRead()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    QString* request = new QString(socket->readAll());

    qDebug() << request->toAscii();
    if (*request == "<policy-file-request/>")
    {
        QString policy = "<cross-domain-policy><allow-access-from domain='*' to-ports='*'/></cross-domain-policy>";
        socket->write(policy.toUtf8().append(QChar::Null));
        socket->flush();
    }
    else
        emit requestReceived(socket, *request);
}

void QServerSide::onResponseReady(QList<void*> sockets, QString response)
{
    foreach (void* socket, sockets)
    {
        //(QTcpSocket*)socket->write(response->toUtf8().append(QChar::Null));
        //(QTcpSocket*)socket->flush();
    }
}

void QServerSide::onDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());

    qDebug() << "Disconnecting client... Socket id:" << socket->socketDescriptor();

    //m_clients.remove(socket->socketDescriptor());
    socket->close();
    socket->deleteLater();

    qDebug() << "Client disconnected.";
}
