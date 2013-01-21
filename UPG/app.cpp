
#include "app.h"
#include "Registry.h"

App::App()
{
    QObject::connect(&m_server, SIGNAL(requestReceived(QObject*, QString)), &m_controller, SLOT(onRequestReceived(QObject*, QString)));
    QObject::connect(&m_controller, SIGNAL(responseReady(QList<QObject*>, QString)), &m_server, SLOT(onResponseReady(QList<QObject*>, QString)));
    QObject::connect(&m_server, SIGNAL(clientDisconnected(QObject*)), &m_controller, SLOT(onClientDisconnected(QObject*)));

    QFile file("E:/Development/Projects/UPG/build/debug/word_rus.txt");
    QList<QString>* words = new QList<QString>();
    if(file.open(QIODevice::ReadOnly))
    {
        QString* temp = new QString();
        *temp = temp->fromUtf8(file.readAll());
        QStringList str = temp->split(' ');
        foreach (QString string, str)
            words->append(string);
    }

    Registry* registry = Registry::instance();
    registry->wordsSet(*words);
}

