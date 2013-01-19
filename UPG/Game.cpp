#include "Game.h"
#include <QTime>
#include "Registry.h"

Game::Game()
{
}

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
    if (state == Game::PREGAME)
        reset();
    m_state = state;
    return SUCCESS;
}

ErrorCode Game::makePlayer(User *user)
{
    if (this->isPlayer(user)) return USER_ALREADY_PLAYER;

    m_players.append(m_observers.takeAt(m_observers.indexOf(user)));

    return SUCCESS;
}

ErrorCode Game::makeObserver(User *user)
{
    if (this->isObserver(user)) return USER_ALREADY_OBSERVER;

    m_observers.append(m_players.takeAt(m_players.indexOf(user)));

    return SUCCESS;
}

QString Game::getName()
{
    return m_name;
}

QString Game::getSourceWord()
{
    return m_word;
}

QString Game::getQuestion()
{
    return m_question;
}

void Game::openWord()
{
    m_openedChars = m_word.count();
}

ErrorCode Game::addActivePlayer(int uid, QString word)
{
    QPair<int, QString> temp;
    temp.first = uid;
    temp.second = word;
    m_activePlayers.append(temp);
    return SUCCESS;
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

bool Game::isPlayer(User *user)
{
    return m_players.contains(user);
}

bool Game::isObserver(User *user)
{
    return m_observers.contains(user);
}

void Game::reset()
{
    m_openedChars = 0;
    m_state = PREGAME;
    m_activePlayers.clear();
    m_host = NULL;
    m_question = QString();
    m_word = QString();
}

void Game::openNextChar()
{
    m_openedChars++;
}

void Game::setQuestion(QString question)
{
    m_question = question;
}

void Game::clearActive()
{
    m_activePlayers.clear();
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

ErrorCode Game::getObservers(QList<User*>& observers)
{
    observers = m_observers;

    return SUCCESS;
}

ErrorCode Game::getActivePlayers(QList<QPair<int, QString> > &activePlayers)
{
    activePlayers = m_activePlayers;

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

ErrorCode Game::chooseHost()
{
    int temp = randomInt(0, m_players.count() - 1);
    m_host = m_players.value(temp);//->getUid();
    return SUCCESS;
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

int Game::getOpenedChars()
{
    return m_openedChars;
}

int Game::getActivePlayersCount()
{
    return m_activePlayers.count();
}
