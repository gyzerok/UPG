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
    ErrorCode           getState(GameState& state);
    ErrorCode           getName(QString& name);
    ErrorCode           getHost(User* user);
    ErrorCode           getUsers(QList<User*>& users);
    ErrorCode           getPlayers(QList<User*>& players);

    ErrorCode           addUser(User* user);
    ErrorCode           setWord(QString word);

    bool            checkPass(QString pass);

    void*           chooseHost();
    //void setHost(void);

    GameState       m_state;


private:
    int             randomInt(int low, int high);
    int             generateGid();

    int             m_gid;
    QString         m_name;
    QString         m_pass;
    int             m_maxUsers;
    QList<User*>    m_observers;

    QList<User*>    m_players;
    QString         m_word;
    QString         m_question;
    User*           m_host;
};

#endif // GAME_H
