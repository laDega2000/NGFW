#ifndef URL_CONF_H
#define URL_CONF_H
#include "Policy.h"
#include "domain.h"
#include <string>
#include <vector>
#include "inter_conf.h"
//#include "poli_ob.h"
using namespace std;

class url_conf : public inter_conf
{

public:

    std::vector<domain> domlist;
    url_conf();
     void add(string sss);
     base get(string ss,base bo)override;
    void update(base rr,string nom);
     base get_all(base b);
    //void set_sup_policy(Rule rr,string nom);
   // void add() override;
    //base* get(string ss) override;
};



#endif