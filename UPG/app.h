#ifndef _APP_H
#define _APP_H


#include "qserverside.h"
#include "QController.h"

class App {
  public:
    App();


  private:
    QServerSide m_server;

    QController m_controller;

};
#endif
