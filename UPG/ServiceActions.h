#ifndef SERVICEACTIONS_H
#define SERVICEACTIONS_H

#include <QObject>
#include <QString>
#include "Error.h"
#include "User.h"
#include "Game.h"

class ServiceActions
{
public:
    ServiceActions();
    static ErrorCode login(int uid, QObject* socket, QList<QObject*>& sockets);
    static ErrorCode logout(QObject* socket);
    static ErrorCode createGame(QString name, QString pass, QObject* socket, QList<QObject*>& sockets, int& gid);
    static ErrorCode joinGame(int uid, int gid, QObject* socket, QList<QObject*>& sockets);
    static ErrorCode exitGame(int uid, QObject* socket, QList<QObject*>& sockets);
    static ErrorCode getGameList(QObject* socket, QList<QObject*> sockets, QList<Game*>& gameList);
};

#endif // SERVICEACTIONS_H
