#ifndef INTERFACE_CONF_H
#define INTERFACE_CONF_H
#include <string>
#include <vector>
#include "inter_conf.h"
#include "base.h"
#include "interfaces.h"
//#include "poli_ob.h"
using namespace std;

class interface_conf : public inter_conf
{

public:

    vector<interfaces>interface_tab;
    interface_conf();
     void add(string sss);
     base get(string ss,base bo)override;
    void update(base rr,string nom);
    base get_all(base b);
    //void set_sup_policy(Rule rr,string nom);
   // void add() override;
    //base* get(string ss) override;
};



#endif