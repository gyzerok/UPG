#ifndef GAME_H
#define GAME_H

#include <QList>
#include <QString>
#include "Error.h"
#include "User.h"

class Game
{
public:
    Game(QString name, QString pass, int maxUsers = 10);
    int getGid();
    QString getName();
    bool checkPass(QString pass);
    Error addUser(User* user);

    void* chooseHost();
    //void setHost(void);

private:
    int randomInt(int low, int high);
    int generateGid();

    int             m_gid;
    QString         m_name;
    QString         m_pass;
    int             m_maxUsers;
    QList<User*>    m_users;

    QList<User*>    m_players;
    QString         m_word;
    QString         m_question;
    User*           m_host;
};

#endif // GAME_H
