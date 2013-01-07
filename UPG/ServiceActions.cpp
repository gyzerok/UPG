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
