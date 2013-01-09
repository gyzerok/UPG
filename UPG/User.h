#ifndef USER_H
#define USER_H

#include "Error.h"
#include <QString>
#include <QObject>

class User
{
public:
    User(int uid, QObject* socket);

    QObject*    getSocket();
    int         getUid();
    int         getCurrentGid();

    ErrorCode   setCurrentGid(int gid);

    ErrorCode   removeCurrentGid();

    QString     m_guessword;
private:
    int         m_uid;
    int         m_gid;
    QObject*    m_socket;
};

#endif // USER_H
