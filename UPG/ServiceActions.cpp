#include "Registry.h"
#include "ServiceActions.h"

ServiceActions::ServiceActions()
{
}

Error ServiceActions::login(int uid, void* socket)
{
    Registry* registry = Registry::instance();
    if (registry->isUserOnline(uid)) return USER_ALREADY_ONLINE;

    User user(uid, socket);
    registry->addUser(uid, &user);

    return SUCCESS;
}

Error ServiceActions::createGame(QString name, QString pass, int& gid)
{
    Registry* registry = Registry::instance();

    Game game(name, pass);
    registry->addGame(game.getGid(), &game);
    gid = game.getGid();

    return SUCCESS;
}

Error ServiceActions::joinGame(int uid, int gid, QList<void*>& sockets)
{
    Error err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    if (registry->isGameExist(gid)) return GAME_DOES_NOT_EXIST;
    Game* game = registry->getGame(gid);
    err = game->addUser(registry->getUser(uid));
    if (err == SUCCESS)
            registry->addUserToGame(uid, game);

    return err;
}
