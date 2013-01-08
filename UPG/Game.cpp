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

QString Game::toString()
{
    return "_";
}

int Game::getGid()
{
    return m_gid;
}

ErrorCode Game::getState(Game::GameState &state)
{
    state = m_state;

    return SUCCESS;
}

ErrorCode Game::changeState(Game::GameState state)
{
    /*
      TODO:
      Сделать свитч-кейс
    */
    m_state = state;
    return SUCCESS;
}

QString Game::getName()
{
    return m_name;
}

ErrorCode Game::getHost(User** user)
{
    *user = m_host;

    return SUCCESS;
}

ErrorCode Game::setWord(QString word)
{
    m_word = word;

    return SUCCESS;
}

ErrorCode Game::removeUser(User *user)
{
    if (m_players.contains(user))
        m_players.removeOne(user);
    else if (m_observers.contains(user))
        m_observers.removeOne(user);
    else
        return THERE_IS_NO_SUCH_USER_IN_THAT_GAME;

    return user->removeCurrentGid();
}

bool Game::checkPass(QString pass)
{
    return m_pass == pass;
}

bool Game::isEmpty()
{
    if (m_players.count() + m_observers.count() == 0) return true;
    else return false;
}

ErrorCode Game::getUsers(QList<User*>& users)
{
    QList<User*> result;
    result.append(m_players);
    result.append(m_observers);

    users = result;

    return SUCCESS;
}

ErrorCode Game::getPlayers(QList<User*>& players)
{
    players = m_players;

    return SUCCESS;
}

ErrorCode Game::getGuessers(QMap<void*, QString> &guessers)
{
    guessers = m_guessers;

    return SUCCESS;
}

ErrorCode Game::addGuesser(void* guesser, QString word)
{
    if (m_guessers.count()>2)
        return  TOO_MANY_GUESSERS;
    m_guessers.insert(guesser,word);
    return SUCCESS;
}

int Game::getCurUserCount()
{
    return m_players.count() + m_observers.count();
}

ErrorCode Game::addUser(User *user)
{
    if (m_players.count() + m_observers.count() > m_maxUsers) return GAME_IS_FULL;

    m_observers.append(user);

    return SUCCESS;
}

void* Game::chooseHost()
{
    int temp = randomInt(0, m_players.count() - 1);
    m_host = m_players.value(temp)->getSocket();
    return m_host;
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

int Game::getMaxUserCount()
{
    return m_maxUsers;
}
