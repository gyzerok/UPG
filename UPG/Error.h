#ifndef ERROR_H
#define ERROR_H

enum Error
{
    SUCCESS,
    UNKNOWN_ERROR,
    USER_ALREADY_ONLINE,
    GAME_IS_FULL,
    GAME_DOES_NOT_EXIST,
    NOT_ENOUGH_PLAYERS_TO_START_THE_GAME,
    YOU_ARE_NOT_A_HOST
};

#endif // ERROR_H
