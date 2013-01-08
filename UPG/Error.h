#ifndef ERROR_H
#define ERROR_H

#include <QMap>
#include <QString>

enum ErrorCode
{
    SUCCESS = 0,
    UNKNOWN_ERROR,
    USER_ALREADY_ONLINE,
    USER_ALREADY_IN_GAME,
    USER_IS_NOT_IN_GAME,
    GAMELIST_IS_EMPTY,
    USERLIST_IS_EMPTY,
    GAME_IS_FULL,
    GAME_DOES_NOT_EXIST,
    NOT_ENOUGH_PLAYERS_TO_START_THE_GAME,
    YOU_ARE_NOT_A_HOST,
    YOU_CAN_NOT_OFFER_A_WORD_NOW,
    HEAD,
    TOO_MANY_GUESSERS,
    THERE_IS_NO_SUCH_USER_IN_THAT_GAME,
    UNKNOWN_REQUEST_TYPE,
    INCORRECT_XML,
    ARE_YOU_KIDDING_ME
};

class Error
{
public:
    Error();
    QString getString(ErrorCode errorCode);

private:
    QMap<ErrorCode,QString> m_errors;
};

#endif // ERROR_H
