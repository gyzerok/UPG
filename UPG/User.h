#ifndef USER_H
#define USER_H

#include "Error.h"
class User
{
public:
    User(int uid, void* socket);
    void* getSocket();
    int getUid();

private:
    int     m_uid;
    void*   m_socket;
};

#endif // USER_H
