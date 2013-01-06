#include "User.h"

User::User(int uid, void* socket)
{
    m_uid = uid;
    m_socket = socket;
}

void* User::getSocket()
{
    return m_socket;
}

int User::getUid()
{
    return m_uid;
}
