#include <QtXml/QXmlStreamReader>
#include <QtXml/QXmlStreamWriter>
#include "QParser.h"

QParser::QParser(QString *request)
{
    m_request = *request;
    m_opened = false;
    m_xml = new QXmlStreamReader(m_request);
}

ErrorCode QParser::next(QString *tag, QString *value)
{
    ErrorCode success = UNKNOWN_ERROR;
    if (!m_opened)
    {
        m_opened = true;
        while (!(m_xml->atEnd()) && !(m_xml->name() == "request"))
            m_xml->readNext();
    }

    m_xml->readNext();
    QString olo = m_xml->qualifiedName().toString();
    QString _tag = m_xml->name().toString();
    if (!(m_xml->tokenType()==QXmlStreamReader::EndElement))
    {
        *tag = _tag;
        QString _value = m_xml->readElementText();
        if (m_xml->tokenType()!=QXmlStreamReader::EndDocument)
        {
            *value = _value;
            success = SUCCESS;
        }
    }

    return success;
}

QString QParser::toString(User *user)
{
    return "_";
}

QString QParser::toString(Game *game)
{
    return "_";
}

QString QParser::toString(QMap<int, User *> users)
{
    return "_";
}

QString QParser::toString(QMap<int, Game *> games)
{
    return "_";
}

QString QParser::toString(ErrorCode errorCode)
{
    Error error;
    return error.getString(errorCode);
}
