#include "Securite_Context.h"
Securite_Context::Securite_Context(){this->strategy=NULL;}
//Securite_Context::Securite_Context(strategieSEC* strateg): strategy(strateg) {}

bool Securite_Context::execute_strategy(char *packet, int packet_len, Policy& p, tabses& s,tabdomain& tab)
{
    return strategy->execute(packet, packet_len, p,s,tab);
}

void Securite_Context::set_strategy(strategieSEC* strategy)
{
    this->strategy = strategy;
}
