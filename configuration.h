#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "Policy.h"
#include "tabdomain.h"
#include "tabses.h"
#include "tab_route.h"
#include "tab_nat.h"
#include <string>
#include <vector>
#include "inter_conf.h"
//#include "poli_ob.h"
using namespace std;

class configuration : public inter_conf
{

public:

    vector<Policy>poli;
    configuration();
     void add(string sss);
     base get(string ss,base bo)override;
    void update(Rule rr,string nom);
    //void set_sup_policy(Rule rr,string nom);
    void add() override;
    //base* get(string ss) override;
};



#endif