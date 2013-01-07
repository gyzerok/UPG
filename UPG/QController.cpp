#include "Action.h"
#include "ServiceActions.h"
#include "GameActions.h"
#include "QController.h"

QController::QController()
{
}

void QController::onRequestReceived(void* socket, QString request)
{
    ErrorCode err = UNKNOWN_ERROR;
    QList<void*> sockets;

    sockets.clear();
    sockets.append(socket);

    int type;
    switch (type)
    {   
        case Action::S_LOG_IN:
            //err = ServiceActions::login(parsedRequest.value(1).toInt(), socket);
            break;
        case Action::S_CREATE_GAME:
            break;
    }

    QString response;
    emit responseReady(sockets, response);
}
