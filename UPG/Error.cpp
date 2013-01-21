#include "Error.h"

Error::Error()
{
    m_errors[SUCCESS]                               = "Success!";
    m_errors[UNKNOWN_ERROR]                         = "Unknown error";
    m_errors[USER_ALREADY_ONLINE]                   = "This user is already online";
    m_errors[USER_ALREADY_IN_GAME]                  = "You are already in game";
    m_errors[USER_IS_NOT_IN_GAME]                   = "This user is not in game";
    m_errors[GAMELIST_IS_EMPTY]                     = "There are no games right now";
    m_errors[USERLIST_IS_EMPTY]                     = "There are no users right now";
    m_errors[GAME_IS_FULL]                          = "This game is full";
    m_errors[GAME_DOES_NOT_EXIST]                   = "This game does not exist";
    m_errors[NOT_ENOUGH_PLAYERS_TO_START_THE_GAME]  = "There are not enough players to start the game";
    m_errors[YOU_ARE_NOT_A_HOST]                    = "Only host can make up a word";
    m_errors[YOU_CAN_NOT_OFFER_A_WORD_NOW]          = "You can not offer a word now";
    m_errors[TOO_MANY_GUESSERS]                     = "There are too many guessers";
    m_errors[THERE_IS_NO_SUCH_USER_IN_THAT_GAME]    = "There is no such user in that game";
    m_errors[UNKNOWN_REQUEST_TYPE]                  = "Unknown request type";
    m_errors[INCORRECT_XML]                         = "Incorrect xml";
    m_errors[ARE_YOU_KIDDING_ME]                    = "Are you kidding me?";
    m_errors[USER_ALREADY_OBSERVER]                 = "You are already observer";
    m_errors[USER_ALREADY_PLAYER]                   = "You are already player";
}

QString Error::getString(ErrorCode errorCode)
{
    return m_errors.value(errorCode);
}
