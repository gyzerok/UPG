#ifndef SERVICEACTIONS_H
#define SERVICEACTIONS_H

#include <QString>
#include "Error.h"
#include "User.h"
#include "Game.h"

class ServiceActions
{
public:
    ServiceActions();
    static ErrorCode login(int uid, void* socket, QList<void*>& sockets);
    static ErrorCode createGame(QString name, QString pass, void* socket, QList<void*>& sockets, int& gid);
    static ErrorCode joinGame(int uid, int gid, QList<void*>& sockets);
    static ErrorCode exitGame(int uid, void* socket, QList<void*>& sockets);
    static ErrorCode getGameList(void* socket, QList<void*> sockets, QList<Game*>& gameList);
};

#endif // SERVICEACTIONS_H
