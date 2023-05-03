#ifndef USER_CONF_H
#define USER_CONF_H
#include "inter_conf.h"
#include <string>
#include <vector>
#include "inter_conf.h"
#include "groupe.h"
#include "base.h"
//#include "poli_ob.h"
using namespace std;

class user_conf : public inter_conf
{

public:

    vector<groupe>group;
    user_conf();
     void add(string sss);
     base get(string ss,base bo);
    void update(base rr,string nom);
     base get_all(base b);
    //void set_sup_policy(Rule rr,string nom);
   // void add() override;
    //base* get(string ss) override;
};



#endif