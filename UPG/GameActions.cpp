#include "Error.h"
#include "Game.h"
#include "Registry.h"
#include "GameActions.h"

GameActions::GameActions()
{

}

Error GameActions::startGame(int gid, QList<void *>& sockets)
{
    Error err = UNKNOWN_ERROR;

    Registry* registry = Registry::instance();

    Game* game;
    err = registry->getGame(gid, game);

    QList<User*> users;
    if (err == SUCCESS)
        err = game->getUsers(users);

    if (err == SUCCESS)
        foreach (User* user, users)
            sockets.append(user->getSocket());

    if (err == SUCCESS)
    {
        QList<User*> players;
        err = game->getPlayers(players);

        if (players.count() < 3)
            return NOT_ENOUGH_PLAYERS_TO_START_THE_GAME;
        else
            return SUCCESS;
    }

    return err;
}

Error GameActions::makeaWord(int gid, QString word, void* socket, QList<void *>& sockets)
{
    Error err = UNKNOWN_ERROR;

    Registry* registry = Registry::instance();

    Game* game;
    err = registry->getGame(gid, game);

    User* host;
    if (err == SUCCESS)
        err = game->getHost(host);

    if (socket != host->getSocket())
    {
        sockets.append(socket);
        err = YOU_ARE_NOT_A_HOST;
    }
    else
    {
        game->setWord(word);
        QList<User*> users;
        err = game->getUsers(users);

        foreach (User* user, users)
            sockets.append(user->getSocket());
    }

    return err;
}

Error GameActions::offeraWord(Game game, QString word, void *socket, QList<void *>& sockets)
{
    Error err = UNKNOWN_ERROR;

    if ( game.m_state != game.GAME_STARTED )
            return YOU_CAN_NOT_OFFER_A_WORD_NOW;

}

