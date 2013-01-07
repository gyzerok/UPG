#include "App.h"

App::App()
{
    QObject::connect(&m_server, SIGNAL(requestReceived(void*, QString)), &m_controller, SLOT(onRequestReceived(void*, QString)));
    QObject::connect(&m_controller, SIGNAL(responseReady(QList<void*>, QString)), &m_server, SLOT(onResponseReady(QList<void*>, QString)));
}

