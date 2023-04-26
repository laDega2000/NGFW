#include "network_conf.h"

network_conf::network_conf(/* args */)
{

}
 void network_conf::add(string ss){
    aplication a(ss);
    this->tab_app.app_tab.push_back(a);


 }

 base network_conf::get(string ss,base bo){
    for(aplication p : this->tab_app.app_tab){
        if(p.name==ss){bo.pb=p;}
    }
    return bo;
 }

    /*void network_conf::update(base rr,string nom){
        std::vector<aplication_tab>popo;
        aplication_tab pipi;
        for(aplication po : this->tab_app.app_tab){
           
        if(po.name==nom)
        {
            
            
            pipi.app_tab=po;
            pipi.addRule(rr.rul);
            popo.push_back(pipi);
        }else{ popo.push_back(po);;printf("pas de politique correspendante");}
        poli.swap(popo);
    }
    }*/