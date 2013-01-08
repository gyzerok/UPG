#ifndef REGISTRY_H
#define REGISTRY_H

#include <QMap>
#include "Game.h"
#include "User.h"

class Registry
{
public:
    static Registry* instance() {
        if(!m_instance)
            m_instance = new Registry();
        return m_instance;
    }

    bool                    isUserOnline(int uid);
    bool                    isGameExist(int gid);

    void                    addUser(int uid, User* user);
    void                    addGame(int gid, Game* game);
    void                    removeUser(int uid);
    void                    removeGame(int gid);

    ErrorCode               getUser(int uid, User** user);
    ErrorCode               getUserList(QList<User*>& userList);
    ErrorCode               getGame(int gid, Game** game);
    ErrorCode               getGameList(QList<Game*>& gameList);

    QMap<int, Game*>        m_games;
    QMap<int, User*>        m_users;

private:
    Registry();

    static Registry*        m_instance;

};

#endif // REGISTRY_H
