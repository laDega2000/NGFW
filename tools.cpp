#include "tools.h"
#include <regex>



tools::tools(){}


bool tools::isDNSPacket(char* packet) {

   
    // Accéder au champ DNS header QR (bit 0-1)
    char* dnsHeader = packet + sizeof(iphdr) + sizeof(udphdr);
    return ((dnsHeader[2] & 0x80) == 0); // retourne true si QR est 0 (requete DNS)


   
}

bool tools::isQuery( char* packet) {
    char* dnsPayload = packet + sizeof(iphdr) + sizeof(udphdr);
    if (dnsPayload[2] & 0x80 == 0x00 && dnsPayload[3] & 0x01 == 0x01) {
        return true;
    }
    return false;
}





// Fonction pour extraire le nom de domaine à partir d'un paquet DNS
char* tools::extractDomainName(char* packet) {

   // int packetSize=sizeof(packet);
    // On vérifie d'abord que le paquet est de type DNS
    iphdr* ipHeader = (iphdr*) packet;
    if (ipHeader->protocol != IPPROTO_UDP) return NULL;

    udphdr* udpHeader = (udphdr*) (packet + sizeof(iphdr));
    if (ntohs(udpHeader->dest) != 53) return NULL;


    // On avance jusqu'à la section de question DNS
    int packetSize=ntohs(ipHeader->tot_len) + sizeof(iphdr) + sizeof(udphdr);
    const char* dnsPayload = packet + sizeof(iphdr) + sizeof(udphdr);
    int offset = 12; // Taille de l'en-tête DNS fixe
    while (offset < packetSize && *(dnsPayload + offset) != 0) {
        offset += (*(dnsPayload + offset) + 1);
    }

    // On extrait le nom de domaine
    char* domainName = new char[256];
    int i = 0;
    while (offset < packetSize && *(dnsPayload + offset) == 0) {
        offset++;
    }
    while (offset < packetSize && *(dnsPayload + offset) != 0) {
        if (i > 0) domainName[i++] = '.';
        int length = *(dnsPayload + offset);
        for (int j = 0; j < length; j++) {
            domainName[i++] = *(dnsPayload + offset + 1 + j);
        }
        offset += length + 1;
    }
    domainName[i] = '\0';

    return domainName;
}


std::string tools::is_zone(std::string ip){
    std::regex regx("^(192\\.168\\.)[0-9]+\\.[0-9]+$");
    if(std::regex_match(ip,regx)){
        return "trust";
    }else return "untrust";
}