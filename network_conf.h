
#include "inter_conf.h"
#include "aplication.h"
class network_conf: public inter_conf
{

public:
    aplication_tab tab_app;
     void add(string sss);
     base get(string ss,base bo)override;
    void update(base rr,string nom);
    network_conf(/* args */);
    
};


