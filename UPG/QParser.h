#ifndef QPARSER_H
#define QPARSER_H

#include <QtCore>
#include <QString>
#include "Error.h"
#include "Game.h"
#include "User.h"
#include "Action.h"

class QParser
{
public:
    QParser(QString *request);
    ErrorCode next(QString *tag, QString *value);
    static QString constructResponse(ErrorCode errorCode, int type, QString msg);
    static QString toString(User* user);
    static QString toString(Game* game);
    static QString toString(QList<User*>& users);
    static QString toString(QList<Game*>& games);

private:
    QString m_request;
    QXmlStreamReader* m_xml;
    bool m_opened;
};

#endif // QPARSER_H
