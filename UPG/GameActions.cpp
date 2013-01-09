#include "Error.h"
#include "Game.h"
#include "Registry.h"
#include "GameActions.h"

GameActions::GameActions()
{
}

ErrorCode GameActions::startGame(int gid, QList<QObject*>& sockets, Game** gameout)
{
    ErrorCode err = UNKNOWN_ERROR;

    Registry* registry = Registry::instance();

    Game* game;
    err = registry->getGame(gid, &game);


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
        {
            err = game->chooseHost();
            if (err == SUCCESS)
                err = game->changeState(Game::GAME_STARTED);
        }
    }
    if (err == SUCCESS)
        *gameout = game;

    return err;
}

ErrorCode GameActions::makeaWord(int uid, QObject* socket, QList<QObject*>& sockets, QString word, Game** gameout)
{
    ErrorCode err = UNKNOWN_ERROR;

    Registry* registry = Registry::instance();

    User* user;
    err = registry->getUser(uid, &user);

    Game* game;
    if (err == SUCCESS)
        err = registry->getGame(user->getCurrentGid(),&game);

    if (err == SUCCESS)
    {
        User* host;
        if (err == SUCCESS)
            err = game->getHost(&host);

        if (socket != host->getSocket())
        {
            sockets.append(socket);
            err = YOU_ARE_NOT_A_HOST;
        }
        else
        {
            game->setWord(word);
            game->openNextChar();
            game->changeState(Game::WORD_MADE_UP);
            QList<User*> users;
            err = game->getUsers(users);

            foreach (User* user, users)
                sockets.append(user->getSocket());
        }
    }
    if ( err == SUCCESS )
        *gameout = game;

    return err;
}


ErrorCode GameActions::offeraWord(int uid, QObject *socket, QList<QObject*>& sockets, QString word, Game** gameout)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    User* user;
    err = registry->getUser(uid, &user);

    Game* game;
    if (err == SUCCESS)
        err = registry->getGame(user->getCurrentGid(),&game);

    Game::GameState gameState;
    if (err == SUCCESS)
        err = game->getState(gameState);

    if (err == SUCCESS && gameState == Game::QUESTION_ASKED)
        return YOU_CAN_NOT_OFFER_A_WORD_NOW;

    err = game->addActivePlayer(uid, word);
    if (err == SUCCESS && game->getActivePlayersCount() == 2)
        err = game->changeState(Game::CONTACT);
    if (err == SUCCESS)
    {
        QList<User*> temp;
        err = game->getUsers(temp);
        if (err == SUCCESS)
            foreach (User* usr, temp)
                sockets.append(usr->getSocket());
        *gameout = game;
    }
    return err;
}

ErrorCode GameActions::askQuestion(int uid, QObject *socket, QList<QObject *> &sockets, QString question, Game** gameout)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    User* user;
    err = registry->getUser(uid, &user);

    Game* game;
    if (err == SUCCESS)
        err = registry->getGame(user->getCurrentGid(),&game);

    Game::GameState gameState;
    if (err == SUCCESS)
        err = game->getState(gameState);

    if (err == SUCCESS && ( gameState == Game::WORD_MADE_UP || gameState == Game::CONTACT_FAILED || gameState == Game::CONTACT_SUCCEED ) )
    {
        game->setQuestion(question);
        err = game->changeState(Game::QUESTION_ASKED);
        if (err == SUCCESS)
        {
            QList<User*> temp;
            game->getUsers(temp);
            foreach (User* usr, temp)
                sockets.append(usr->getSocket());
            *gameout = game;
        }
    }
    return err;
}

ErrorCode GameActions::breakContact(int uid, QObject *socket, QList<QObject *> &sockets, QString word, Game** gameout)
{
    ErrorCode err = UNKNOWN_ERROR;
    Registry* registry = Registry::instance();

    User* user;
    err = registry->getUser(uid, &user);

    Game* game;
    if (err == SUCCESS)
        err = registry->getGame(user->getCurrentGid(),&game);

    Game::GameState gameState;
    if (err == SUCCESS)
        err = game->getState(gameState);
    if ( err == SUCCESS )
    {
        game->addActivePlayer(uid,word);
        bool trigga = true;
        for (int i=0; i<game->getOpenedChars(); i++)
        {
            if ( word[i] != game->getSourceWord()[i] )
            {
                trigga = false;
                break;
            }
        }

        if ( trigga )
            err = game->changeState(Game::CONTACT_FAILED);
        else
        {
            QList<QPair<int, QString> > temp;
            game->getActivePlayers(temp);
            QString firstWord = temp[0].second;
            QString secondWord = temp[1].second;
            trigga = true;
            for ( int i = 0; i<game->getOpenedChars(); i++)
            {
                if ( firstWord[i] != secondWord[i] )
                {
                    game->changeState(Game::CONTACT_FAILED);
                    trigga = false;
                    break;
                }
            }
            if (trigga)
            {
                game->changeState(Game::CONTACT_SUCCEED);
            }

            QList<User*> users;
            game->getPlayers(users);
            foreach (User* usr, users)
                sockets.append(usr->getSocket());

            *gameout = game;
        }
    }

    return err;
}



