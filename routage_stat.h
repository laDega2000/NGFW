#ifndef STATIC_ROUTING_H
#define STATIC_ROUTING_H
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <pcap.h>
#include <vector>
#include "strategieRTG.h"
#include <cstdint>
#include <string>



// Classe pour gérer la table de routage statique
class routage_stat : public strategieRTG {
public:

    routage_stat();
     std::string route(packet pac,inter_conf* r,tab_nat t);
    
   
};

#endif  // STATIC_ROUTING_H

