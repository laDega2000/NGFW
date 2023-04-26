#ifndef TABSES_H
#define TABSES_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "session.h"

class tabses
{
public:
    std::vector<session> sessions;
    tabses();
    void addSession(session newSession);
    bool isPacketInSession(std::string srcIP, std::string destIP, int srcPort, int destPort);
};

#endif
