#ifndef APP_H
#define APP_H

#include "QServerSide.h"
#include "QParser.h"
#include "QController.h"

class App
{
public:
    App();

private:
    QServerSide     m_server;
    QParser         m_parser;
    QController     m_controller;
};

#endif // APP_H
