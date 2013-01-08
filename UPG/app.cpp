
<<<<<<< HEAD
#include "app.h"

App::App(){
=======
App::App()
{
    QObject::connect(&m_server, SIGNAL(requestReceived(QObject*, QString)), &m_controller, SLOT(onRequestReceived(QObject*, QString)));
    QObject::connect(&m_controller, SIGNAL(responseReady(QList<QObject*>, QString)), &m_server, SLOT(onResponseReady(QList<QObject*>, QString)));
>>>>>>> 6dbb9a8df3f53e2e28dd65718cd43d026d73c488
}

