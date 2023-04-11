#ifndef TAB_ROUTE_H
#define TAB_ROUTE_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
// Structure pour stocker une entrée de la table de routage statique
struct tab_stat
{
    std::string adr_dest;
    std::string next_hop;
};

class tab_route
{

public:
std::vector<tab_stat>stat;
    tab_route();
    
};

#endif
