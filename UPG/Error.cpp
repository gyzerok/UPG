#include "Error.h"

Error::Error()
{
    m_errors[SUCCESS] = "Успех!";
    m_errors[UNKNOWN_ERROR] = "Неизвестная ошибка";
    m_errors[USER_ALREADY_ONLINE] = "Такой пользователь уже находится в игре";
    m_errors[USER_ALREADY_IN_GAME] = "Вы уже находитесь в игре";
}

QString Error::getString(ErrorCode errorCode)
{
    return m_errors.value(error);
}
