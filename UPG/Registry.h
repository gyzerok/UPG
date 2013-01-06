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
    bool isUserOnline(int uid);
    bool isGameExist(int gid);
    void addUser(int uid, User* user);
    void addGame(int gid, Game* game);
    void addUserToGame(int uid, Game* game);
    User* getUser(int uid);
    Game* getGame(int gid);

    QMap<int, Game*>        m_registry;
    QMap<int, Game*>        m_games;
    QMap<int, User*>        m_users;

private:
    Registry();

    static Registry*        m_instance;

};

#endif // REGISTRY_H
