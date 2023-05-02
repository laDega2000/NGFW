#ifndef PACKET_H
#define PACKET_H
#include <string>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <pcap.h>
#include <iostream>
#include "zone.h"
#include "user.h"
using namespace std;
class packet
{

public:
    string src_ip;
    string dst_ip;
    string src_mac;
    string dst_mac;
    int src_port;
    int dst_port;
    zone src_zone;
    zone dst_zone;
    user users;;
    char* payload;
    char* header;
    packet(const u_char* pack);
    
};

#endif
