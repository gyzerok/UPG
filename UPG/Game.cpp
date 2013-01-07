#include "Game.h"
#include <QTime>
#include "Registry.h"

Game::Game(QString name, QString pass, int maxUsers)
{
    m_state = PREGAME;
    m_name = name;
    m_pass = pass;
    m_maxUsers = maxUsers;
    m_gid = generateGid();
    m_host = NULL;
}

int Game::getGid()
{
    return m_gid;
}

Error Game::getState(Game::GameState &state)
{
    state = m_state;

    return SUCCESS;
}

Error Game::getName(QString& name)
{
    name = m_name;

    return SUCCESS;
}

Error Game::getHost(User* user)
{
    user = m_host;

    return SUCCESS;
}

Error Game::setWord(QString word)
{
    m_word = word;

    return SUCCESS;
}

bool Game::checkPass(QString pass)
{
    return m_pass == pass;
}

Error Game::getUsers(QList<User*>& users)
{
    QList<User*> result;
    result.append(m_players);
    result.append(m_observers);

    users = result;

    return SUCCESS;
}

Error Game::getPlayers(QList<User*>& players)
{
    players = m_players;

    return SUCCESS;
}

Error Game::addUser(User *user)
{
    if (m_players.count() + m_observers.count() > m_maxUsers) return GAME_IS_FULL;

    m_observers.append(user);

    return SUCCESS;
}

void* Game::chooseHost()
{
    int temp = randomInt(0, m_players.count() - 1);
    return m_players.value(temp)->getSocket();
}

int Game::randomInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

int Game::generateGid()
{
    Registry* registry = Registry::instance();

    int temp = randomInt(0,500000);
    if (registry->isGameExist(temp))
        return generateGid();
    else
        return temp;
}
