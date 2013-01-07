#include "Error.h"

Error::Error()
{
    m_errors[SUCCESS] = "�����!";
    m_errors[UNKNOWN_ERROR] = "����������� ������";
    m_errors[USER_ALREADY_ONLINE] = "����� ������������ ��� ��������� � ����";
    m_errors[USER_ALREADY_IN_GAME] = "�� ��� ���������� � ����";
}

QString Error::getString(ErrorCode errorCode)
{
    return m_errors.value(error);
}
