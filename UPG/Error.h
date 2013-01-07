#ifndef ERROR_H
#define ERROR_H

#include <QMap>
#include <QString>

enum ErrorCode
{
    SUCCESS,
    UNKNOWN_ERROR,
    USER_ALREADY_ONLINE,
    USER_ALREADY_IN_GAME,
    GAME_IS_FULL,
    GAME_DOES_NOT_EXIST,
    NOT_ENOUGH_PLAYERS_TO_START_THE_GAME,
    YOU_ARE_NOT_A_HOST,
    YOU_CAN_NOT_OFFER_A_WORD_NOW,
};

class Error
{
public:
    Error();
    QString getString(ErrorCode error);

private:
    QMap<ErrorCode,QString> m_errors;
};

#endif // ERROR_H
