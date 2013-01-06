#include "App.h"

App::App()
{
    QObject::connect(&m_server, SIGNAL(requestReceived(void*, QString)), &m_parser, SLOT(onRequestReceived(void*, QString)));
    QObject::connect(&m_parser, SIGNAL(responseReady(QList<void*>, QString)), &m_server, SLOT(onResponseReady(QList<void*>, QString)));

    QObject::connect(&m_parser, SIGNAL(requestReady(void*, QStringList)), &m_controller, SLOT(onRequestReady(void*, QStringList)));
    QObject::connect(&m_controller, SIGNAL(actionComplete(QList<void*>, QStringList)), &m_parser, SLOT(onActionComplete(QList<void*>, QStringList)));


}

