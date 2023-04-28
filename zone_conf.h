#ifndef ZONE_CONF_H
#define ZONE_CONF_H

#include <string>
#include <vector>
#include "inter_conf.h"
#include "zone.h"
//#include "poli_ob.h"
using namespace std;

class zone_conf : public inter_conf
{

public:

    std::vector<zone>zoo;
    zone_conf();
     void add(string sss);
     base get(string ss,base bo)override;
    void update(base rr,string nom);
    //void set_sup_policy(Rule rr,string nom);
   // void add() override;
    //base* get(string ss) override;
};



#endif