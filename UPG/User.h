#ifndef USER_H
#define USER_H

#include "Error.h"
#include <QString>

class User
{
public:
    User(int uid, void* socket);

    void*   getSocket();
    int     getUid();
    Error   getCurrentGid(int& gid);

    Error   setCurrentGid(int gid);

    QString m_guessword;
private:
    int     m_uid;
    int     m_gid;
    void*   m_socket;
};

#endif // USER_H
