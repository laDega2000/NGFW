#ifndef INTERFACES_H
#define INTERFACES_H
#include "Firewall.cpp"
class interfaces
{

public:
    int id;
     Firewall firewall;
    interfaces();
     void send(char* packet);
     void receive(const u_char* packet,pcap_pkthdr *header);
   
};


#endif