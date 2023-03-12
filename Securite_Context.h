#ifndef SECURITE_CONTEXT_H
#define SECURITE_CONTEXT_H

#include <string>
#include "strategieSEC.h"
#include "Policy.h"
#include "tabses.h"

class Securite_Context
{
public:
    Securite_Context Securite(strategieSEC &strategy);
    bool execute_strategy(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy p, tabses s);
    void set_strategy(strategieSEC* strategy);
    

    strategieSEC* strategy;
};

#endif // SECURITE_CONTEXT_H
