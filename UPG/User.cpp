#include "User.h"
#include <QTime>
#include "Registry.h"

User::User(int uid, QObject* socket)
{
    m_uid = uid;
    m_gid = NULL;
    m_socket = socket;
}

QObject* User::getSocket()
{
    return m_socket;
}

int User::getUid()
{
    return m_uid;
}

int User::getCurrentGid()
{
    return  m_gid;
}

ErrorCode User::setCurrentGid(int gid)
{
    if (m_gid != NULL) return USER_ALREADY_IN_GAME;

    m_gid = gid;

    return SUCCESS;
}

ErrorCode User::removeCurrentGid()
{
    if (m_gid == NULL) return USER_IS_NOT_IN_GAME;

    m_gid = NULL;

    return SUCCESS;
}
