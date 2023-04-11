#include "Routage_Context.h"

Routage_Context::Routage_Context(){this->strategy=NULL;}
//Routage_Context::Routage_Context(strategieSEC* strateg): strategy(strateg) {}

bool Routage_Context::execute_strategy(char *src_mac, int src_mac_len, char *packet, int packet_len,tab_route r)
{
    return strategy->route(src_mac,src_mac_len,packet, packet_len,r);
}

void Routage_Context::set_strategy(strategieRTG* strategy)
{
    this->strategy = strategy;
}
