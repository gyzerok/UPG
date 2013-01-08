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
    void onRequestReceived(QObject* socket, QString request);
    void onClientDisconnected(QObject* socket);

signals:
    void responseReady(QList<QObject*> sockets, QString response);
};

#endif // QCONTROLLER_H
