#ifndef POLICY_H
#define POLICY_H

#include <vector>
#include <iostream>
#include "Rule.h"
#include "base.h"
class Policy : public base
{

public:
   std::vector<Rule> rules;
    std::string name;
   // void supRule(Rule rr);
    Policy();
    void addRule(Rule r);
};

#endif
