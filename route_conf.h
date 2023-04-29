#ifndef ROUTE_CONF_H
#define ROUTE_CONF_H
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


class route_conf : public inter_conf
{

public:

    std::vector<tab_stat>stat;
    route_conf();
     void add(string sss);
     base get(string ss,base bo)override;
    void update(base rr,string nom);
    //void set_sup_policy(Rule rr,string nom);
   // void add() override;
    //base* get(string ss) override;
};



#endif