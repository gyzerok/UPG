#ifndef GAMEACTIONS_H
#define GAMEACTIONS_H

#include "Error.h"
#include "Game.h"
#include <QString>
#include <QList>

class GameActions
{
public:
    GameActions();
    static Error startGame(Game game, QList<void*> sockets);
    static Error makeaWord(Game game, QString word, void* socket, QList<void*> sockets);
};

#endif // GAMEACTIONS_H
