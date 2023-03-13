#include "Securite_Context.h"
Securite_Context::Securite_Context(){this->strategy=NULL;}
//Securite_Context::Securite_Context(strategieSEC* strateg): strategy(strateg) {}

bool Securite_Context::execute_strategy(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy p, tabses s)
{
    return strategy->execute(srcIP, destIP, srcPort, destPort, p, s);
}

void Securite_Context::set_strategy(strategieSEC* strategy)
{
    this->strategy = strategy;
}
