#ifndef GAME_H
#define GAME_H

#include <QList>
#include <QString>
#include <QPair>
#include "Error.h"
#include "User.h"

class Game
{
public:
    enum GameState
    {
        PREGAME = 0,
        GAME_STARTED,
        WORD_MADE_UP,
        QUESTION_ASKED,
        CONTACT,
        CONTACT_SUCCEED,
        CONTACT_FAILED,
        WORD_GUESSED,
    };

    Game();
    Game(QString name, QString pass, int maxUsers = 10);

    int                         getGid();


    ErrorCode                   getState(GameState& state);
    ErrorCode                   getHost(User** user);
    ErrorCode                   getUsers(QList<User*>& users);
    ErrorCode                   getPlayers(QList<User*>& players);
    ErrorCode                   getObservers(QList<User*>& observers);
    ErrorCode                   getActivePlayers(QList<QPair<int, QString> > &activePlayers);
    int                         getCurUserCount();
    int                         getMaxUserCount();
    int                         getOpenedChars();
    int                         getActivePlayersCount();
    QString                     getName();
    QString                     getSourceWord();
    QString                     getQuestion();

    ErrorCode                   addActivePlayer(int uid, QString word);
    ErrorCode                   addUser(User* user);
    ErrorCode                   setWord(QString word);
    ErrorCode                   changeState(GameState state);
    ErrorCode                   chooseHost();
    ErrorCode                   makePlayer(User* user);
    ErrorCode                   makeObserver(User* user);

    ErrorCode                   removeUser(User* user);

    bool                        checkPass(QString pass);
    bool                        isEmpty();
    bool                        isPlayer(User* user);
    bool                        isObserver(User* user);
    void                        reset();
    void                        openNextChar();
    void                        setQuestion(QString question);
    void                        clearActive();

private:
    int                         randomInt(int low, int high);
    int                         generateGid();



    int                         m_gid;
    QString                     m_name;
    QString                     m_pass;
    int                         m_maxUsers;
    QList<User*>                m_observers;

    QList<QPair<int, QString> > m_activePlayers;
    User*                       m_host;
    QString                     m_question;
    QString                     m_word;
    QList<User*>                m_players;
    GameState                   m_state;
    int                         m_openedChars;
};

#endif // GAME_H
