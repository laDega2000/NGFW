#ifndef INTERFACES_H
#define INTERFACES_H
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include "zone.h"
#include "packet.h"
#include "tools.h"
#include "groupe.h"
#include "user.h"
#include "inter_conf.h"
#include "user_conf.h"
class interfaces
{

public:
    int id;
    base b;
    
   tools tt;
    zone zon;
    interfaces();
    interfaces(int idd ,std::string zon);
     void send(char* packet);
     packet receive(int i,inter_conf* ii);
   
};


#endif