#ifndef BASE_H
#define BASE_H
#include<string>
#include<vector>
#include "Rule.h"
#include "zone.h"
#include "groupe.h"
#include "user.h"
//#include "user.h"
class base
{

public:
   std::vector<Rule> rules;
    std::string name;
    std::vector<zone> zii;
    groupe use;
    user u;
    bool test;
    zone zi;
    Rule rul;
    base();
};

#endif

