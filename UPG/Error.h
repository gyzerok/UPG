#ifndef ERROR_H
#define ERROR_H

#include <QMap>
#include <QString>

enum ErrorCode
{
    SUCCESS                                     = 0,
    UNKNOWN_ERROR                               = 1,
    USER_ALREADY_ONLINE                         = 2,
    USER_ALREADY_IN_GAME                        = 3,
    USER_IS_NOT_IN_GAME                         = 4,
    GAMELIST_IS_EMPTY                           = 5,
    USERLIST_IS_EMPTY                           = 6,
    GAME_IS_FULL                                = 7,
    GAME_DOES_NOT_EXIST                         = 8,
    NOT_ENOUGH_PLAYERS_TO_START_THE_GAME        = 9,
    YOU_ARE_NOT_A_HOST                          = 10,
    YOU_CAN_NOT_OFFER_A_WORD_NOW                = 11,
    HEAD                                        = 12,
    TOO_MANY_GUESSERS                           = 13,
    THERE_IS_NO_SUCH_USER_IN_THAT_GAME          = 14,
    UNKNOWN_REQUEST_TYPE                        = 15,
    INCORRECT_XML                               = 16,
    ARE_YOU_KIDDING_ME                          = 17,
    USER_ALREADY_OBSERVER                       = 18,
    USER_ALREADY_PLAYER                         = 19,
    FAILED_TO_BREAK_CONTACT                     = 20
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
