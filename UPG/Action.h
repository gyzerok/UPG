#ifndef ACTION_H
#define ACTION_H

class Action
{
public:
    enum Type
    {
        S_LOG_IN = 0,
        S_LOG_OUT = 1,
        S_GET_GAME_LIST = 2,
        S_CREATE_GAME = 3,
        S_JOIN_GAME = 4,
        S_EXIT_GAME = 5,
        S_CHANGE_USER_ROLE = 6,
        G_SOURCE_WORD = 7,
        G_ASK_QUESTION = 8,
        G_MAKE_CONTACT = 9,
        G_BREAK_CONTACT = 10,
        G_START_GAME = 11,
        G_MAKE_A_WORD = 12,
        G_OFFER_A_WORD = 13,
        G_END_GAME = 14
    };
};

#endif // ACTION_H
