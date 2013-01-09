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
        PREGAME = 0,
        GAME_STARTED,
        WORD_OFFERED,
        QUESTION_ASKED,
        CONTACT,
        CONTACT_SUCCEED,
        CONTACT_FAILED
    };

    Game();
    Game(QString name, QString pass, int maxUsers = 10);

    int                     getGid();


    ErrorCode               getState(GameState& state);
    ErrorCode               getHost(User** user);
    ErrorCode               getUsers(QList<User*>& users);
    ErrorCode               getPlayers(QList<User*>& players);
    ErrorCode               getObservers(QList<User*>& observers);
    ErrorCode               getGuessers(QMap<void*, QString>& guessers);
    int                     getCurUserCount();
    int                     getMaxUserCount();
    int                     getOpenedChars();
    QString                 getName();
    QString                 getSourceWord();
    QString                 getQuestion();

    ErrorCode               addGuesser(void* guesser, QString word);
    ErrorCode               addUser(User* user);
    ErrorCode               setWord(QString word);
    ErrorCode               changeState(GameState state);
    ErrorCode               makePlayer(User* user);
    ErrorCode               makeObserver(User* user);

    ErrorCode               removeUser(User* user);

    bool                    checkPass(QString pass);
    bool                    isEmpty();
    bool                    isPlayer(User* user);
    bool                    isObserver(User* user);

private:
    int                     randomInt(int low, int high);
    int                     generateGid();
    void*                   chooseHost();

    int                     m_gid;
    QString                 m_name;
    QString                 m_pass;
    int                     m_maxUsers;
    QList<User*>            m_observers;

    QMap<void*, QString>    m_guessers;
    QList<User*>            m_players;
    GameState               m_state;
    QString                 m_word;
    int                     m_openedChars;
    QString                 m_question;
    User*                   m_host;
};

#endif // GAME_H
