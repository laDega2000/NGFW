#ifndef STRATEGIE_SEC_H
#define STRATEGIE_SEC_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"
#include "tabdomain.h"

class strategieRTG {
public:
    virtual bool route(char *src_mac, int src_mac_len, char *packet, int packet_len)=0;
};

#endif // STRATEGIE_SEC_H
