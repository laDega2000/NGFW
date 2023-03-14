#ifndef SECURITE_CONTEXT_H
#define SECURITE_CONTEXT_H

#include <string>
#include "strategieSEC.h" // inclure le fichier d'en-tête strategieSEC.h
#include "Policy.h"
#include "tabses.h"

class Securite_Context
{
public:
    strategieSEC* strategy;
    Securite_Context();
   // Securite_Context(strategieSEC* strateg);
    bool execute_strategy(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy& p, tabses& s);
    void set_strategy(strategieSEC* strategy);
};

#endif // SECURITE_CONTEXT_H
