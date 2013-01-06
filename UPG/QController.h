#ifndef QCONTROLLER_H
#define QCONTROLLER_H

#include <QStringList>
#include <QtXml/QXmlInputSource>
#include <QtXml/QXmlSimpleReader>

class QController : public QObject
{
    Q_OBJECT
public:
    QController();

public slots:
    void onRequestReady(void* socket, QStringList parsedRequest);

signals:
    void actionComplete(QList<void*> sockets, QStringList response);
};

#endif // QCONTROLLER_H
