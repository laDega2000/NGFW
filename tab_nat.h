#ifndef TAB_NAT_H
#define TAB_NAT_H
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
// Structure pour stocker une entrée de la table de routage statique
struct tab_nat_stat
{
    std::string ip_prive;
    std::string ip_public;
};

class tab_nat
{

public:
    std::vector<tab_nat_stat>tabn;
    tab_nat();
    
};

#endif
