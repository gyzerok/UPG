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

QString QParser::constructResponse(ErrorCode error, QString msg)
{
    /*
      <response>
        <error>1</error>
        остальное опционально в зависимости от запроса
      </response>
    */
    m_xml = new QXmlStreamReader(m_request);
    QString result, tag, value;

    result.append("<response>");
    result.append(QParser::toString(error));
    result.append(msg);
    result.append("</response>");

    return result;
}

QString QParser::toString(User *user)
{
    int gid;
    user->getCurrentGid(gid);
    // <uid>123</uid>
    // <gid>321<gid>
    QString result;
    result.append("<uid>");
    result.append(user->getUid());
    result.append("</uid>");
    result.append("<gid>");
    result.append(gid);
    result.append("</gid>");
    return result;
}

QString QParser::toString(Game *game)
{
    // <gid>123</gid>
    // <name>имя</name>
    // <max_players>1</max_players>
    QString result;
    result.append("<gid>");
    result.append(game->getGid());
    result.append("</gid>");
    result.append("<name>");
    result.append(game->getName());
    result.append("</name>");
    result.append("<max_players>");
    result.append(game->getMaxUserCount());
    result.append("</max_players>");
    return result;
}

QString QParser::toString(QList<User *> users)
{
    // <uid>123</uid>
    // <gid>321<gid>
    // n-раз
    QString result;
    foreach (User* user, users)
        result.append(QParser::toString(user));

    return result;
}

QString QParser::toString(QList<Game *> games)
{
    QString result = "<games>";

    foreach (Game* game, games)
    {
        // <game id="10203" name="OLOLO" curPlayers="10" maxPlayers="15">
        result.append(game->getGid());
        result.append("\" name=\"");
        result.append(game->getName());
        result.append("\" curPlayers=\"");
        result.append(game->getCurUserCount());
        result.append("\" maxPlayers=\"");
        result.append(game->getMaxUserCount());
        result.append("\">");
    }
    result.append("</games>");

    return result;
}

QString QParser::toString(ErrorCode errorCode)
{
    Error error;
    QString result = "<error>" + error.getString(errorCode) + "</error>";
    return result;
}
