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

private:
    int             m_gid;
    QString         m_name;
    QString         m_pass;
    int             m_maxUsers;
    QList<User*>    m_users;

    QString         m_word;
    QString         m_question;
};

#endif // GAME_H
