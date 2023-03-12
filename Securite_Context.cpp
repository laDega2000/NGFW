#include "Securite_Context.h"
#include "strategieSEC.h"

Securite_Context Securite_Context::Securite(strategieSEC &strateg){Securite_Context context;context-> strategy=strateg;}

bool Securite_Context::execute_strategy(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy p, tabses s)
{
    return strategy->execute(srcIP, destIP, srcPort, destPort, p, s);
}

void Securite_Context::set_strategy(strategieSEC* strategy)
{
    this->strategy = strategy;
}
