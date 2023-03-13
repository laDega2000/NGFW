#ifndef POLICY_H
#define POLICY_H

#include <vector>
#include <iostream>
#include "Rule.h"

class Policy
{

public:
   std::vector<Rule> rules;

    Policy();
    void addRule(Rule r);
};

#endif
