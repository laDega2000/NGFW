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
    bool execute_strategy(char *src_mac, int src_mac_len, char *packet, int packet_len);
    void set_strategy(strategieRTG* strategy);
};

#endif // Routage_Context_H
