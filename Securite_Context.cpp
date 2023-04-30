#include "Securite_Context.h"
Securite_Context::Securite_Context(){this->strategy=NULL;}
//Securite_Context::Securite_Context(strategieSEC* strateg): strategy(strateg) {}

bool Securite_Context::execute_strategy(packet pac, inter_conf* conf, inter_conf* s,tabdomain& tab)
{
    return strategy->execute(pac, conf,s,tab);
}

void Securite_Context::set_strategy(strategieSEC* strategy)
{
    this->strategy = strategy;
}
