#ifndef nat_conf_H
#define nat_conf_H
#include "session.h"
#include "tabses.h"
#include <string>
#include <vector>
#include "inter_conf.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "base.h"

//#include "poli_ob.h"
using namespace std;

class nat_conf : public inter_conf
{

public:

    std::vector<tab_nat_stat>nstat;
    nat_conf();
     void add(string sss);
     base get(string ss,base bo)override;
    void update(base rr,string nom);
     base get_all(base b);
    //void set_sup_policy(Rule rr,string nom);
   // void add() override;
    //base* get(string ss) override;
};



#endif