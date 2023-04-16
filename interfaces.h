#ifndef INTERFACES_H
#define INTERFACES_H
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include "zone.h"
#include "packet.h"
#include "tools.h"
class interfaces
{

public:
    int id;
   tools tt;
    zone zon;
    interfaces();
     void send(char* packet);
     packet receive(int i);
   
};


#endif