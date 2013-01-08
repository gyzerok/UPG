#ifndef GAMEACTIONS_H
#define GAMEACTIONS_H

#include <QObject>
#include <QString>
#include <QList>
#include "Error.h"
#include "Game.h"

class GameActions
{
public:
    GameActions();
    static ErrorCode startGame(int gid, QList<QObject*>& sockets);
    static ErrorCode makeaWord(int gid, QString word, QObject* socket, QList<QObject*>& sockets);
    static ErrorCode guesstheWord(int gid, QString word, QObject* socket, QList<QObject*>& sockets);
    static ErrorCode makeaQuestion(int gid, QString question, QObject* socket, QList<QObject*>& sockets);
    static ErrorCode offeraWord(int gid, QString word, QObject* socket, QList<QObject*>& sockets);
};

#endif // GAMEACTIONS_H
