#ifndef ACTION_H
#define ACTION_H

class Action
{
public:
    enum Type
    {
        S_LOG_IN = 0,
        S_LOG_OUT,
        S_GET_GAME_LIST,
        S_CREATE_GAME,
        S_JOIN_GAME,
        S_EXIT_GAME,
        S_CHANGE_USER_ROLE,
        G_SOURCE_WORD,
        G_ASK_QUESTION,
        G_MAKE_CONTACT,
        G_BREAK_CONTACT,
        G_START_GAME,
        G_MAKE_A_WORD,
        G_OFFER_A_WORD,
        G_END_GAME,
    };
};

#endif // ACTION_H
