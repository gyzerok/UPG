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
    static ErrorCode guesstheWord(int gid, QString word, void* socket, QList<void*>& sockets);
    static ErrorCode makeaQuestion(int gid, QString question, void* socket, QList<void*>& sockets);
    static ErrorCode offeraWord(int gid, QString word, void* socket, QList<void*>& sockets);
};

#endif // GAMEACTIONS_H
