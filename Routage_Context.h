#ifndef ROUTAGE_CONTEXT_H
#define ROUTAGE_CONTEXT_H

#include <string>
#include "strategieRTG.h" // inclure le fichier d'en-tête strategieSEC.h
#include "Policy.h"
#include "tabses.h"
#include "tabdomain.h"
class Routage_Context
{
public:
    strategieRTG* strategy;
    Routage_Context();
   // Routage_Context(strategieSEC* strateg);
    std::string execute_strategy(char *src_mac, int src_mac_len, char *packet, int packet_len,tab_route r,tab_nat t);
    void set_strategy(strategieRTG* strategy);
};

#endif // Routage_Context_H
