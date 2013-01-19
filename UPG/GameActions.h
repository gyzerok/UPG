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
    static ErrorCode startGame(int uid, QList<QObject*>& sockets, Game** gameout);
    static ErrorCode makeaWord(int uid, QObject* socket, QList<QObject*>& sockets, QString word, Game** gameout);
    static ErrorCode offeraWord(int uid, QObject *socket, QList<QObject*> &sockets, QString word, Game** gameout);
    static ErrorCode askQuestion(int uid, QObject* socket, QList<QObject*> &sockets, QString question, Game** gameout);
    static ErrorCode breakContact(int uid, QObject* socket, QList<QObject*> &sockets, QString word, Game** gameout);
    static ErrorCode endGame(int uid, QObject* socket, QList<QObject*>& sockets, Game** outGame);
private:
    static void reset(Game game);
};

#endif // GAMEACTIONS_H
