#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "session.h"
#include "tabses.h"
#include <string>
#include <vector>
#include "inter_conf.h"
#include "Policy.h"
//#include "poli_ob.h"
using namespace std;

class configuration : public inter_conf
{

public:

    vector<Policy>poli;
    configuration();
     void add(string sss);
     base get(string ss,base bo)override;
    void update(base rr,string nom);
    base get_all(base b);
    //void set_sup_policy(Rule rr,string nom);
   // void add() override;
    //base* get(string ss) override;
};



#endif