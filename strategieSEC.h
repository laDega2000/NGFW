#ifndef STRATEGIE_SEC_H
#define STRATEGIE_SEC_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"

class strategieSEC {
public:
    virtual bool execute(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy& p, tabses& s)=0;
};

#endif // STRATEGIE_SEC_H
