#include "GameActions.h"
#include "Error.h"
#include "Game.h"

GameActions::GameActions()
{

}

Error GameActions::startGame(Game game, void *socket, QList<void *> sockets)
{
    /*
        TODO:
            Согласовать владельцев комнаты. (Кто будет начинать игру?)
            добавить owner при create room и в проверку m_owner == socket
    */

    Error err = UNKNOWN_ERROR;

    foreach (User* user, game.m_users)
    {
        sockets.append(user->getSocket());
    }

    if ( game.m_players.count() < 3 )
        return NOT_ENOUGH_PLAYERS_TO_START_THE_GAME;
    else
        return SUCCESS;
}

Error GameActions::makeaWord(Game game, QString word, void* socket, QList<void *> sockets)
{
    Error err = UNKNOWN_ERROR;

    if ( socket != game.m_host->getSocket() )
    {
        sockets.append(socket);
        return YOU_ARE_NOT_A_HOST;
    }
    else
    {
        game.m_word = word;
        foreach (User* user, game.m_users)
        {
            sockets.append(user->getSocket());
        }
        return SUCCESS;
    }
}
