#ifndef ACTION_H
#define ACTION_H

class Action
{
public:
    enum Type
    {
        S_LOG_IN,
        S_LOG_OUT,
        S_GET_ROOM_LIST,
        S_CREATE_GAME,
        S_ENTER_GAME,
        S_LEAVE_GAME,
        G_SOURCE_WORD,
        G_ASK_QUESTION,
        G_MAKE_CONTACT,
        G_BREAK_CONTACT
    };
};

#endif // ACTION_H
