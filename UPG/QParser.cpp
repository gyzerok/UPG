#include "QParser.h"

QParser::QParser()
{
}

void QParser::onRequestReceived(void *socket, QString request)
{
    QStringList parsedRequest;

    //��� ���������� QString � QStringList

    emit requestReady(socket, parsedRequest);
}

void QParser::onActionComplete(QList<void*> sockets, QStringList response)
{
    QString xmlResponse;

    //��� ���������� QStringList � QString

    emit responseReady(sockets, xmlResponse);
}
