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
    QString constructResponse(ErrorCode error);

private:
    static QString toString(User* user);
    static QString toString(Game* game);
    static QString toString(QList<User*> users);
    static QString toString(QList<Game*> games);
    static QString toString(ErrorCode errorCode);

    QString m_request;
    QXmlStreamReader* m_xml;
    bool m_opened;
};

#endif // QPARSER_H
