#include "QParser.h"

QParser::QParser()
{
}

void QParser::onRequestReceived(void *socket, QString request)
{
    QStringList parsedRequest;

    //Тут превращаем QString в QStringList

    emit requestReady(socket, parsedRequest);
}

void QParser::onActionComplete(QList<void*> sockets, QStringList response)
{
    QString xmlResponse;

    //Тут превращаем QStringList в QString

    emit responseReady(sockets, xmlResponse);
}
