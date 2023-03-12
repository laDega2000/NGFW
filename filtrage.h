#ifndef FILTRAGE_H
#define FILTRAGE_H

#include "strategieSEC.h"

class filtrage : public strategieSEC {
public:
    bool execute(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy p, tabses s) override;
};

#endif // FILTRAGE_H
