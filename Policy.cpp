#include "Policy.h"
#include <sstream> // nécessaire pour utiliser std::istringstream
#include <fstream> // nécessaire pour lire un fichier

Policy::Policy() {
   
}


void Policy::addRule(Rule r) {
    rules.push_back(r);
}
/*void Policy::supRule(Rule rr) {
    rules.pop_back(rr);
}*/