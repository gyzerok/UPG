#include "Action.h"
#include "ServiceActions.h"
#include "GameActions.h"
#include "QController.h"
#include "QParser.h"

QController::QController()
{
}

/*
  ВНИМАНИЕ!!! порядок тегов важен!!!

логин
        <request>
            <type>1</type>
            <uid>2</uid>
        </request>

создание игры
        <request>
            <type>1</type>
            <uid>2</uid>
            <name>olo</type>
            <password>lol</password>
        </request>

вход в игру
        <request>
            <type>1</type>
            <uid>2</uid>
            <gid>3</gid>
        </request>

начало игры
        <request>
            <type>1</type>
            <uid>3</uid>
            <gid>2</gid>
        </request>

загадать слово, слово отгадано, предложить вариант
        <request>
            <type>1</type>
            <uid>2</uid>
            <gid>2</gid>
            <word>слово</word>
        </request>
*/

void QController::onRequestReceived(QObject* socket, QString request)
{
    ErrorCode err = INCORRECT_XML;
    QList<QObject*> sockets;
    QString msg; msg.clear();
    Game* game;

    sockets.clear();

    QParser* parser = new QParser(&request);
    QList<Game *> glist; glist.clear();
    QString tag, value;
    int type = -1;
    int uid = -1;
    bool flag = false;

    if (parser->next(&tag, &value) == SUCCESS)
        if (tag == "type")
        {
            type = value.toInt();
            if (parser->next(&tag, &value) == SUCCESS)
                if (tag == "uid")
                {
                    uid = value.toInt();
                    flag = true;
                }
        }
    if (flag)
    switch (type)
    {
        /*
                    SERVER SIDE ACTIONS
        */
        case Action::S_LOG_IN:
                err = ServiceActions::login(uid, socket, sockets);
            break;

        case Action::S_CREATE_GAME:
            parser->next(&tag, &value);
            if (tag == "name")
            {
                QString name = value;
                parser->next(&tag, &value);
                int gid = 0;
                if (tag == "password")
                {
                    err = ServiceActions::createGame(uid, name, value, socket, sockets, gid);
                    msg.append(QString("<gid>%1</gid>").arg(gid));
                }
            }
            break;

        case Action::S_JOIN_GAME:
            parser->next(&tag, &value);
            if (tag == "gid")
                err = ServiceActions::joinGame(uid, value.toInt(), socket, sockets, &game);
            if (err == SUCCESS)
                msg.append(QParser::toString(game));
            break;

        case Action::S_EXIT_GAME:
            err = ServiceActions::exitGame(uid, socket, sockets, &game);
            if (err == SUCCESS)
                msg.append(QParser::toString(game));
            break;

        case Action::S_GET_GAME_LIST:
            err = ServiceActions::getGameList(uid, socket, sockets, glist);
            msg.append(QParser::toString(glist));
            break;
        /*
                    GAME SIDE ACTIONS
        */
        case Action::G_START_GAME:
            parser->next(&tag, &value);
            if (tag == "gid")
                err = GameActions::startGame(value.toInt(), sockets);
            break;

        case Action::G_MAKE_A_WORD:
            parser->next(&tag, &value);
            if (tag == "gid")
            {
                int gid = value.toInt();
                parser->next(&tag, &value);
                if (tag == "word")
                    err = GameActions::makeaWord(gid, value, socket, sockets);
            }
            break;

        case Action::G_GUESS_THE_WORD:
            parser->next(&tag, &value);
            if (tag == "gid")
            {
                int gid = value.toInt();
                parser->next(&tag, &value);
                if (tag == "word")
                    err = GameActions::guesstheWord(gid, value, socket, sockets);
            }
            break;

        case Action::G_OFFER_A_WORD:
            parser->next(&tag, &value);
            if (tag == "gid")
            {
                int gid = value.toInt();
                parser->next(&tag, &value);
                if (tag == "word")
                    err = GameActions::offeraWord(gid, value, socket, sockets);
            }
            break;

        default:
            err = UNKNOWN_REQUEST_TYPE;
    }

    QString response;
    response = QParser::constructResponse(err, type, msg);
    emit responseReady(sockets, response);
}

void QController::onClientDisconnected(QObject *socket)
{
    ServiceActions::logout(socket);
}

