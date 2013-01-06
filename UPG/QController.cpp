#include "Action.h"
#include "ServiceActions.h"
#include "GameActions.h"
#include "QController.h"

QController::QController()
{
}

void QController::onRequestReady(void* socket, QStringList parsedRequest)
{
    Error err = UNKNOWN_ERROR;
    QStringList response;
    QList<void*> sockets;
    sockets.clear();
    sockets.append(socket);

    switch (parsedRequest.value(1).toInt())
    {   
        case Action::S_LOG_IN:
            err = ServiceActions::login(parsedRequest.value(1).toInt(), socket);
            //response = new QString(err);
            break;
        //case Action::S_CREATE_GAME:


    }

    emit actionComplete(sockets, response);
}
