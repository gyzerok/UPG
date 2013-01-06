#ifndef QPARSER_H
#define QPARSER_H

#include <QString>
#include <QStringList>
#include <QList>

class QParser : public QObject
{
    Q_OBJECT
public:
    QParser();

public slots:
    void onRequestReceived(void* socket, QString request);
    void onActionComplete(QList<void*> sockets, QStringList response);

signals:
    void requestReady(void* socket, QStringList parsedRequest);
    void responseReady(QList<void*> sockets, QString xmlResponse);
};

#endif // QPARSER_H
