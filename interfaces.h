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
//#include "base.h"
#include <iostream>

//using namespace std;
class interfaces
{

public:
    int id;
    const char* file_name;
    const char* output;
    std::string ip_adr;
   tools tt;
    zone zon;
    interfaces();
   interfaces(const char* filename,const char* output_name ,string ip,std::string zon);
     void send(packet pkt);
     packet receive(int i);
   
};


#endif