#ifndef QPARSER_H
#define QPARSER_H
#include <QtCore>
#include <QString>
#include "Error.h"

class QParser
{
public:
    QParser(QString *request);
    Error next(QString *tag, QString *value);
    static QString ParseResponse();
private:
    QString m_request;
    QXmlStreamReader* m_xml;
    bool m_opened;
};

#endif // QPARSER_H
