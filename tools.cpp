#include "tools.h"
tools::tools(){}


bool tools::isDNSPacket(char* packet) {

    iphdr* ipHeader = (iphdr*) packet;
    if (ipHeader->protocol == IPPROTO_UDP) {
        udphdr* udpHeader = (udphdr*) (packet + sizeof(iphdr));
        char* dnsPayload = packet + sizeof(iphdr) + sizeof(udphdr);
        if (ntohs(udpHeader->dest) == 53) {
            return true;
        }
    }
    return false;
}

bool tools::isQuery( char* packet) {
    char* dnsPayload = packet + sizeof(iphdr) + sizeof(udphdr);
    if (dnsPayload[2] & 0x80 == 0x00 && dnsPayload[3] & 0x01 == 0x01) {
        return true;
    }
    return false;
}

char* tools::extractDomainName( char* packet) {
    char* domainName = new char[256];
    int i = 0;
    int j = 0;
    char* dnsPayload = packet + sizeof(iphdr) + sizeof(udphdr);
    int k = dnsPayload[12];
    while (k != 0) {
        for (int l = 0; l < k; l++) {
            domainName[j++] = dnsPayload[i + l + 1];
        }
        i += k + 1;
        k = dnsPayload[i];
        if (k != 0) {
            domainName[j++] = '.';
        }
    }
    domainName[j] = '\0';
    return domainName;
}