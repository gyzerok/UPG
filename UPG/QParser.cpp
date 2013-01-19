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

QString QParser::constructResponse(ErrorCode errorCode, int type, QString msg)
{
    /*
      <response>
        <error>msg</error>
        <type>1</type>
        остальное опционально в зависимости от запроса
      </response>
    */
    Error error;
    QString result;

    result.append("<response>");
    result.append("<error>");
    result.append(error.getString(errorCode));
    result.append("</error>");
    result.append("<type>");
    result.append(QString("%1").arg(type));
    result.append("</type>");
    result.append("<body>");
    result.append(msg);
    result.append("</body>");
    result.append("</response>");

    return result;
}

QString QParser::toString(User *user)
{
    // <uid>123</uid>
    // <gid>321<gid>
    QString result;
    result.append("<uid>");
    result.append(user->getUid());
    result.append("</uid>");
    result.append("<gid>");
    result.append(user->getCurrentGid());
    result.append("</gid>");
    return result;
}

QString QParser::toString(Game *game)
{
    // <gid>123</gid>
    // <name>имя</name>
    // <max_players>1</max_players>
    QString result;
    if (game == NULL)
        return "<name>DELETED</name><state>0</state><players></players><observers></observers>";
    Game::GameState state; game->getState(state);
    result.append(QString("<name>%1</name>").arg(game->getName()));
    result.append(QString("<state>%1</state>").arg(state));

    result.append("<players>");
    QList<User*> players; game->getPlayers(players);
    foreach (User* player, players)
        result.append(QString("<uid>%1</uid>").arg(player->getUid()));
    result.append("</players>");

    result.append("<observers>");
    QList<User*> observers; game->getObservers(observers);
    foreach (User* observer, observers)
        result.append(QString("<uid>%1</uid>").arg(observer->getUid()));
    result.append("</observers>");

    if (state >= Game::GAME_STARTED)
    {
        User* host;
        game->getHost(&host);
        result.append(QString("<host>%1</host>").arg(host->getUid()));
    }

    if (state >= Game::WORD_MADE_UP)
    {
        result.append(QString("<sourceword>%1</sourceword>").arg(game->getSourceWord()));
        result.append(QString("<openedchars>%1</openedchars>").arg(game->getOpenedChars()));
    }

    QList<QPair<int, QString> > temp;
    game->getActivePlayers(temp);
    if (state >= Game::QUESTION_ASKED)
    {
        result.append(QString("<question>%1</question>").arg(game->getQuestion()));
        result.append("<activeusers>");
        if (temp.count() == 1 || temp.count() == 2 || temp.count() == 3)
            result.append(QString("<uid>%1</uid>").arg(temp[0].first));
        if (temp.count() == 2 || temp.count() == 3)
            result.append(QString("<uid>%1</uid>").arg(temp[1].first));
        result.append("</activeusers>");
    }

    /*if (state >= Game::CONTACT)
    {
        result.append(QString("<firstActivePlayer>%1</firstActivePlayer>").arg(temp[0].first));
        result.append(QString("<secondActivePlayer>%1</secondActivePlayer>").arg(temp[1].first));
    }*/

    if (state >= Game::CONTACT_SUCCEED)
    {
        result.append(QString("<firstWord>%1</firstWord>").arg(temp[0].second));
        result.append(QString("<secondWord>%1</secondWord>").arg(temp[1].second));
        result.append(QString("<hostWord>%1</hostWord>").arg(temp[2].second));
    }

    return result;
}

QString QParser::toString(QList<User *>& users)
{
    // <uid>123</uid>
    // <gid>321<gid>
    // n-раз
    QString result;
    foreach (User* user, users)
        result.append(QParser::toString(user));

    return result;
}

QString QParser::toString(QList<Game *>& games)
{
    QString result;

    foreach (Game* game, games)
    {
        // <gid>123</gid>
        // <name>OLOLO</name>
        // <curPlayers>10</curPlayers>
        // <maxPlayers>15</maxPlayers>
        result.append("<game>");
        result.append(QString("<gid>%1</gid>").arg(game->getGid()));
        result.append(QString("<name>%1</name>").arg(game->getName()));
        result.append(QString("<curPlayers>%1</curPlayers>").arg(game->getCurUserCount()));
        result.append(QString("<maxPlayers>%1</maxPlayers>").arg(game->getMaxUserCount()));
        result.append("</game>");
    }

    return result;
}
