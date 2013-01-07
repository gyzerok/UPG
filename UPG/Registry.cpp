#include "Registry.h"

bool Registry::isUserOnline(int uid)
{
    return m_users.contains(uid);
}

bool Registry::isGameExist(int gid)
{
    return m_games.contains(gid);
}

void Registry::addUser(int uid, User *user)
{
    m_users.insert(uid, user);
}

void Registry::addGame(int gid, Game *game)
{
    m_games.insert(gid, game);
}

ErrorCode Registry::getUser(int uid, User* user)
{
    user = m_users.value(uid);

    return SUCCESS;
}

ErrorCode Registry::getGame(int gid, Game* game)
{
    game = m_games.value(gid);

    return SUCCESS;
}

Registry::Registry()
{
}

Registry* Registry::m_instance = NULL;
