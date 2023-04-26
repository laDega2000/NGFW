#ifndef DNS_PACKET_FILTER_H
#define DNS_PACKET_FILTER_H

#include <netinet/ip.h>
#include <netinet/udp.h>
//#include "ltins"
#include "tools.h"
#include <cstring>
#include <arpa/inet.h>
#include "strategieSEC.h"
#include "tabdomain.h"
#include "Log.h"

class filtrurl : public strategieSEC{
public:
    filtrurl();
   
    bool execute(packet pac, inter_conf* p, tabses& s,tabdomain& tab);
    iphdr* ipHeader;
    udphdr* udpHeader;
    unsigned char* dnsPayload;
};

#endif