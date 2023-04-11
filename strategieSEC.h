#ifndef STRATEGIE_SEC_H
#define STRATEGIE_SEC_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"
#include "tabdomain.h"

class strategieSEC {
public:
    virtual bool execute( char *packet, int packet_len, Policy& p, tabses& s,tabdomain& tab)=0;
};

#endif // STRATEGIE_SEC_H
