#ifndef PARSER_H
#define PARSER_H
#include <QtCore>
#include <QString>

class QParser
{
public:
    QParser(QString *request);
    bool Next (QString *tag, QString *value);
    static QString ParseResponse();
private:
    QString m_request;
    QXmlStreamReader* m_xml;
    bool m_opened;
};

#endif // PARSER_H
