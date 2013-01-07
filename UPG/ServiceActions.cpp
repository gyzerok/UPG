#include "Registry.h"
#include "ServiceActions.h"

ServiceActions::ServiceActions()
{
}

ErrorCode ServiceActions::login(int uid, void* socket)
{
    Registry* registry = Registry::instance();
    if (registry->isUserOnline(uid)) return USER_ALREADY_ONLINE;

    User user(uid, socket);
    registry->addUser(uid, &user);

    return SUCCESS;
}

ErrorCode ServiceActions::createGame(QString name, QString pass, int& gid)
{
    Registry* registry = Registry::instance();

    Game game(name, pass);
    registry->addGame(game.getGid(), &game);
    gid = game.getGid();

    return SUCCESS;
}

ErrorCode ServiceActions::joinGame(int uid, int gid, QList<void*>& sockets)
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

ErrorCode ServiceActions::exitGame(int uid, void *socket, QList<void*>& sockets)
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

    sockets.append(socket);

    return err;
}

ErrorCode ServiceActions::getGameList(void *socket, QList<void *> sockets, QList<Game *>& gameList)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    err = registry->getGameList(gameList);
    sockets.append(socket);

    return SUCCESS;
}
