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
    static ErrorCode startGame(int gid, QList<void*>& sockets);
    static ErrorCode makeaWord(int gid, QString word, void* socket, QList<void*>& sockets);
    static ErrorCode guesstheWord(Game game, QString word, void* socket, QList<void*>& sockets);
    static ErrorCode makeaQuestion(Game game, QString question, void* socket, QList<void*>& sockets);
    static ErrorCode offeraWord(Game game, QString word, void* socket, QList<void*>& sockets);
};

#endif // GAMEACTIONS_H
