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

void Registry::addUserToGame(int uid, Game *game)
{
    m_registry.insert(uid, game);
}

User *Registry::getUser(int uid)
{
    return m_users.take(uid);
}

Game *Registry::getGame(int gid)
{
    return m_games.take(gid);
}

Registry::Registry()
{
}

Registry* Registry::m_instance = NULL;
