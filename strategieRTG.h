#ifndef STRATEGIE_RTG_H
#define STRATEGIE_RTG_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"
#include "tabdomain.h"
#include "tab_route.h"

class strategieRTG {
public:
    virtual bool route(char *src_mac, int src_mac_len, char *packet, int packet_len,tab_route r)=0;
};

#endif // STRATEGIE_RTG_H
