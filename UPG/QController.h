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
    void onRequestReceived(void* socket, QString request);

signals:
    void responseReady(QList<void*> sockets, QString response);
};

#endif // QCONTROLLER_H
