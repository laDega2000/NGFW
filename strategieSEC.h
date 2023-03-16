#ifndef STRATEGIE_SEC_H
#define STRATEGIE_SEC_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"

class strategieSEC {
public:
    virtual bool execute(char *src_mac, int src_mac_len, char *packet, int packet_len, Policy& p, tabses& s)=0;
};

#endif // STRATEGIE_SEC_H
