#ifndef SERVICEACTIONS_H
#define SERVICEACTIONS_H

#include <QString>
#include "Error.h"

class ServiceActions
{
public:
    ServiceActions();
    static ErrorCode login(int uid, void* socket);
    static ErrorCode createGame(QString name, QString pass, int& gid);
    static ErrorCode joinGame(int uid, int gid, QList<void*>& sockets);
    //static Error exitRoom(int uid)
};

#endif // SERVICEACTIONS_H
