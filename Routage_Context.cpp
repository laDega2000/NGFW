#include "Routage_Context.h"

Routage_Context::Routage_Context(){this->strategy=NULL;}
//Routage_Context::Routage_Context(strategieSEC* strateg): strategy(strateg) {}

packet Routage_Context::execute_strategy(packet pac,inter_conf* r,inter_conf* t)
{
    return strategy->route(pac,r,t);
}

void Routage_Context::set_strategy(strategieRTG* strategy)
{
    this->strategy = strategy;
}
