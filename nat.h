#ifndef NAT_H
#define NAT_H
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <pcap.h>
#include <vector>
#include "strategieRTG.h"
#include <cstdint>
#include <string>
#include "packet.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
// Structure représentant une traduction d'adresse et de port
struct Translation {
    std::string original_ip;
    int original_port;
    std::string translated_ip;
    int translated_port;
};



// Classe pour gérer la table de routage statique
class nat : public strategieRTG {
public:

    nat();
    // Vecteur de traductions d'adresse et de port
     std::vector<Translation> nat_translation;
     packet route(packet pac,inter_conf* r,inter_conf* t);
    packet nat_bidirectionnel(packet packet);
   std::string get_new_public_ip();
   int get_new_public_port();
};

#endif  // STATIC_ROUTING_H

