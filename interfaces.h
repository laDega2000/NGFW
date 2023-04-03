#ifndef INTERFACES_H
#define INTERFACES_H
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include "zone.h"
class interfaces
{

public:
    int id;
   
    zone zon;
    interfaces();
     void send(char* packet);
     const u_char * receive();
   
};


#endif