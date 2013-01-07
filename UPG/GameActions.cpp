#include "GameActions.h"
#include "Error.h"
#include "Game.h"

GameActions::GameActions()
{

}

Error GameActions::startGame(Game game, QList<void *> sockets)
{
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

Error GameActions::offeraWord(Game game, QString word, void *socket, QList<void *> sockets)
{
    Error err = UNKNOWN_ERROR;

    if ( game.m_state != game.GAME_STARTED )
            return YOU_CAN_NOT_OFFER_A_WORD_NOW;

}

