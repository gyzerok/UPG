#ifndef ACTION_H
#define ACTION_H

class Action
{
public:
    enum Type
    {
        S_LOG_IN,
        S_LOG_OUT,
        S_GET_GAME_LIST,
        S_CREATE_GAME,
        S_JOIN_GAME,
        S_EXIT_GAME,
        G_SOURCE_WORD,
        G_ASK_QUESTION,
        G_MAKE_CONTACT,
        G_BREAK_CONTACT,
        G_START_GAME,
        G_MAKE_A_WORD,
        G_GUESS_THE_WORD,
        G_OFFER_A_WORD
    };
};

#endif // ACTION_H
