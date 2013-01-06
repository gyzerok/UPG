#ifndef SERVICEACTIONS_H
#define SERVICEACTIONS_H

#include <QString>
#include "Error.h"

class ServiceActions
{
public:
    ServiceActions();
    static Error login(int uid, void* socket);
    static Error createGame(QString name, QString pass);
    static Error joinGame(int uid, int gid);
};

#endif // SERVICEACTIONS_H
