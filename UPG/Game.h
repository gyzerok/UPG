#ifndef GAME_H
#define GAME_H

#include <QList>
#include <QString>
#include "Error.h"
#include "User.h"

class Game
{
public:
    enum GameState
    {
        PREGAME,
        GAME_STARTED,
        WORD_OFFERED,
        CONTACT
    };

    Game(QString name, QString pass, int maxUsers = 10);
    QString         toString();

    int             getGid();

    ErrorCode       getState(GameState& state);
    ErrorCode       changeState(GameState state);
    ErrorCode       getHost(User* user);
    ErrorCode       getUsers(QList<User*>& users);
    ErrorCode       getPlayers(QList<User*>& players);
    QString         getName();
    int             getCurUserCount();
    int             getMaxUserCount();

    ErrorCode       addUser(User* user);
    ErrorCode       setWord(QString word);
    ErrorCode       removeUser(User* user);

    bool            checkPass(QString pass);

private:
    int             randomInt(int low, int high);
    int             generateGid();
    void*           chooseHost();

    int             m_gid;
    QString         m_name;
    QString         m_pass;
    int             m_maxUsers;
    QList<User*>    m_observers;

    QList<User*>    m_players;
    GameState       m_state;
    QString         m_word;
    QString         m_question;
    User*           m_host;
};

#endif // GAME_H
