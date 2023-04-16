#ifndef BASE_H
#define BASE_H
#include<string>
#include<vector>
#include "Rule.h"
#include "zone.h"
class base
{

public:
   std::vector<Rule> rules;
    std::string name;
    std::vector<zone> zii;
    zone zi;
    Rule rul;
    base();
};

#endif

