#include "Error.h"

Error::Error()
{
    m_errors[SUCCESS] = "Success!";
    m_errors[UNKNOWN_ERROR] = "Unknown error";
    m_errors[USER_ALREADY_ONLINE] = "Such user already online";
    m_errors[USER_ALREADY_IN_GAME] = "Yur are already in game";
}

QString Error::getString(ErrorCode errorCode)
{
    return m_errors.value(errorCode);
}
