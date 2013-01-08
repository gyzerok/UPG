#include "Error.h"
#include "Game.h"
#include "Registry.h"
#include "GameActions.h"

GameActions::GameActions()
{

}

ErrorCode GameActions::startGame(int gid, QList<void*>& sockets)
{
    ErrorCode err = UNKNOWN_ERROR;

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

ErrorCode GameActions::makeaWord(int gid, QString word, void* socket, QList<void*>& sockets)
{
    ErrorCode err = UNKNOWN_ERROR;

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

ErrorCode GameActions::guesstheWord(int gid, QString word, void *socket, QList<void*> &sockets)
{
    return SUCCESS;
}

ErrorCode GameActions::offeraWord(int gid, QString word, void *socket, QList<void*>& sockets)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    Game* game;
    err = registry->getGame(gid, game);

    Game::GameState gameState;
    if (err == SUCCESS)
        err = game->getState(gameState);

    if (err == SUCCESS && gameState != Game::GAME_STARTED)
        return YOU_CAN_NOT_OFFER_A_WORD_NOW;

    err = game->addGuesser(socket,word);
    if (err == SUCCESS)
        err = game->changeState(Game::WORD_OFFERED);
    if (err == SUCCESS)
    {
        QList<User*> temp;
        err = game->getUsers(temp);
        if (err == SUCCESS)
            foreach (User* usr, temp)
                sockets.append(usr->getSocket());
    }
    return err;
}

