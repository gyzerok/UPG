#include "QController.h"

QController::QController()
{
}

void QController::onRequestReady(void* socket, QStringList parsedRequest)
{
    QStringList response;

    /*switch (parsedRequest)
    {

    }*/
    QList<void*> sockets;
    emit actionComplete(sockets, response);
}
