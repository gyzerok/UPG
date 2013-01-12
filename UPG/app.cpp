
#include "app.h"

App::App()
{
    QObject::connect(&m_server, SIGNAL(requestReceived(QObject*, QString)), &m_controller, SLOT(onRequestReceived(QObject*, QString)));
    QObject::connect(&m_controller, SIGNAL(responseReady(QList<QObject*>, QString)), &m_server, SLOT(onResponseReady(QList<QObject*>, QString)));
    QObject::connect(&m_server, SIGNAL(clientDisconnected(QObject*)), &m_controller, SLOT(onClientDisconnected(QObject*)));
}

