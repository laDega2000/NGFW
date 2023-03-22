#ifndef TABDOMAIN_H_
#define TABDOMAIN_H_

// Définitions de classe, fonctions, etc.


#include <vector>
#include "domain.h"
#include <fstream>
#include <sstream>
#include <iostream>
class tabdomain
{
 
public:
    std::vector<domain> domlist;
    tabdomain();
    void add_domain(std::string);
    bool is_domain(std::string);
};


#endif // _MY_HEADER_H_

