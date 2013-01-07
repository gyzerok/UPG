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
    static Error startGame(Game game, void* socket, QList<void*> sockets);
    static Error makeaWord(Game game, QString word, void* socket, QList<void*> sockets);
    static Error guesstheWord(Game game, QString word, void* socket, QList<void*> sockets);
    static Error makeaQuestion(Game game, QString question, void* socket, QList<void*> sockets);
    static Error offeraWord(Game game, QString word, void* socket, QList<void*> sockets);
};

#endif // GAMEACTIONS_H
