#include "Game.h"

Game::Game(QString name, QString pass, int maxUsers)
{
    m_name = name;
    m_pass = pass;
    m_maxUsers = maxUsers;
}

int Game::getGid()
{
    return m_gid;
}

QString Game::getName()
{
    return m_name;
}

bool Game::checkPass(QString pass)
{
    return m_pass == pass;
}

Error Game::addUser(User *user)
{
    if (m_users.count() > m_maxUsers) return GAME_IS_FULL;

    m_users.append(user);
    return SUCCESS;
}
