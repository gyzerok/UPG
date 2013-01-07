#include "Game.h"
#include <QTime>
#include "Registry.h"

Game::Game(QString name, QString pass, int maxUsers)
{
    m_name = name;
    m_pass = pass;
    m_maxUsers = maxUsers;
    m_gid = generateGid();
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

void* Game::chooseHost()
{
    int temp = randomInt(0,m_users.count()-1);
    return m_users.value(temp)->getSocket();
}

int Game::randomInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

int Game::generateGid()
{
    Registry* registry = Registry::instance();
    int temp = randomInt(0,500000);
    if ( registry->m_games.contains(temp) )
        return generateGid();
    else
        return temp;
}
