#include "Securite_Context.h"
Securite_Context::Securite_Context(){this->strategy=NULL;}
//Securite_Context::Securite_Context(strategieSEC* strateg): strategy(strateg) {}

bool Securite_Context::execute_strategy(char *src_mac, int src_mac_len, char *packet, int packet_len, Policy& p, tabses& s)
{
    return strategy->execute(src_mac,src_mac_len,packet, packet_len, p,s);
}

void Securite_Context::set_strategy(strategieSEC* strategy)
{
    this->strategy = strategy;
}
