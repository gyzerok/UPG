#include "Registry.h"
#include "ServiceActions.h"

template <class T> void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        delete *ppT;
        *ppT = NULL;
    }
}

ServiceActions::ServiceActions()
{
}

ErrorCode ServiceActions::login(int uid, QObject* socket, QList<QObject*>& sockets)
{
    Registry* registry = Registry::instance();
    if (registry->isUserOnline(uid)) return USER_ALREADY_ONLINE;

    User* user = new User(uid, socket);
    registry->addUser(uid, user);

    sockets.append(socket);

    return SUCCESS;
}

ErrorCode ServiceActions::logout(QObject *socket)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    QList<User*> userList;
    err = registry->getUserList(userList);

    foreach (User* user, userList)
    {
        if (socket == user->getSocket())
        {
            int uid = user->getUid();
            registry->removeUser(uid);
            int gid;
            err = user->removeCurrentGid();
            ServiceActions::exitGame(uid, new QObject(), *(new QList<QObject*>()));
            SafeRelease(&user);
        }
    }

    return err;
}

ErrorCode ServiceActions::createGame(int uid, QString name, QString pass, QObject* socket, QList<QObject*>& sockets, int& gid)
{
    Registry* registry = Registry::instance();

    Game* game = new Game(name, pass);
    registry->addGame(game->getGid(), game);
    gid = game->getGid();

    sockets.append(socket);

    return SUCCESS;
}

ErrorCode ServiceActions::joinGame(int uid, int gid, QObject* socket, QList<QObject *>& sockets)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    if (registry->isGameExist(gid)) err = GAME_DOES_NOT_EXIST;

    Game* game;
    if (err == SUCCESS)
        err = registry->getGame(gid, game);

    User* user;
    if (err == SUCCESS)
        err = registry->getUser(uid, user);

    if (err == SUCCESS)
        err = game->addUser(user);

    if (err == SUCCESS)
        err = user->setCurrentGid(game->getGid());

    return err;
}

ErrorCode ServiceActions::exitGame(int uid, QObject *socket, QList<QObject*>& sockets)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    User* user;
    err = registry->getUser(uid, user);

    int gid;
    if (err == SUCCESS)
        err = user->getCurrentGid(gid);

    Game* game;
    if (err == SUCCESS)
        err = registry->getGame(gid, game);

    if (err == SUCCESS)
        err = game->removeUser(user);

    if (err == SUCCESS)
        if (game->isEmpty())
        {
            int gid = game->getGid();
            registry->removeGame(gid);
            SafeRelease(&game);
        }

    if (socket != NULL)
        sockets.append(socket);

    return err;
}

<<<<<<< HEAD
ErrorCode ServiceActions::getGameList(void *socket, QList<void*> sockets, QList<Game*>& gameList)
=======
ErrorCode ServiceActions::getGameList(int uid, QObject *socket, QList<QObject *> sockets, QList<Game *>& gameList)
>>>>>>> 6dbb9a8df3f53e2e28dd65718cd43d026d73c488
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    err = registry->getGameList(gameList);
    sockets.append(socket);

    return SUCCESS;
}
