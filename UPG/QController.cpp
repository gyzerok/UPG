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
            <id>2</id>
        </request>

создание игры
        <request>
            <type>1</type>
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
            <gid>2</gid>
        </request>

загадать слово, слово отгадано, предложить вариант
        <request>
            <type>1</type>
            <gid>2</gid>
            <word>слово</word>
        </request>
*/

void QController::onRequestReceived(QObject* socket, QString request)
{
    ErrorCode err = UNKNOWN_ERROR;
    QList<QObject*> sockets;
    QString msg; msg.clear();

    sockets.clear();

    QParser* parser = new QParser(&request);
    QString tag, value;
    int type = -1;

    if (parser->next(&tag, &value) == SUCCESS)
        if (tag == "type")
            type = value.toInt();

    switch (type)
    {
        case Action::S_LOG_IN:
            parser->next(&tag, &value);
            if (tag == "id")
                err = ServiceActions::login(value.toInt(), socket, scokets);
            break;
        case Action::S_CREATE_GAME:
            parser->next(&tag, &value);
            if (tag == "name")
            {
                QString name = value;
                parser->next(&tag, &value);
                int gid;
                if (tag == "password")
                    err = ServiceActions::createGame(name, value, socket, sockets, gid);
                msg.append((QString)gid);
            }
            break;
        case Action::S_ENTER_GAME:
            parser->next(&tag, &value);
            if (tag == "uid")
            {
                int uid = value.toInt();
                parser->next(&tag, &value);
                //if (tag == "gid")
                    //err = ServiceActions::joinGame(uid, value.toInt(), sockets);
            }
            break;
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
    response = parser->constructResponse(err, msg);
    emit responseReady(sockets, response);
}

void QController::onClientDisconnected(QObject *socket)
{

}
