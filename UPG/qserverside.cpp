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
    {
        qDebug() << "Socket: " << socket->socketDescriptor();
        emit requestReceived(socket, *request);
        //QString temp = "ololo";
        //socket->write(temp.toAscii().append(QChar::Null));
    }
}

void QServerSide::onResponseReady(QList<QObject*> sockets, QString response)
{
    qDebug() << response.toAscii();
    foreach (QObject* socket, sockets)
    {
        QTcpSocket* target = qobject_cast<QTcpSocket*>(socket);
        qDebug() << "Socket: " << target->socketDescriptor();
        target->write(response.toUtf8().append(QChar::Null));
        target->flush();
    }
}

void QServerSide::onDisconnected()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());

    emit clientDisconnected(socket);

    qDebug() << "Disconnecting client... Socket id:" << socket->socketDescriptor();

    socket->close();
    socket->deleteLater();

    qDebug() << "Client disconnected.";
}
