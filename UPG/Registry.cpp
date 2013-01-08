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

ErrorCode Registry::getUserList(QList<User*> &userList)
{
    if (m_users.empty()) return USERLIST_IS_EMPTY;

    userList.append(m_users.values());

    return SUCCESS;
}

ErrorCode Registry::getGame(int gid, Game* game)
{
    game = m_games.value(gid);

    return SUCCESS;
}

ErrorCode Registry::getGameList(QList<Game*> &gameList)
{
    if (m_games.empty()) return GAMELIST_IS_EMPTY;

    gameList.append(m_games.values());

    return SUCCESS;
}

Registry::Registry()
{
}

Registry* Registry::m_instance = NULL;
