#ifndef TOOLS_H
#define TOOLS_H
#include <netinet/ip.h>
#include <netinet/udp.h>
//#include "ltins"
#include <cstring>
#include <arpa/inet.h>
#include "strategieSEC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
class tools
{

public:
    tools();
    
    bool isDNSPacket( char* packet);
    bool isQuery( char* packet);
    char* extractDomainName(char* packet);
    std::string is_zone(std::string ip); 
   // decapsule()
};


#endif