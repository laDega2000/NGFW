#include "configuration.h"
#include <iostream>
configuration::configuration(/* args */){
    Policy pa;
    this->add("dega");
    Rule r("192.168.1.2", "192.168.1.255", 137, 137 ,true);
    
    this->update(r,"dega");
   //std::cout<<(this->poli[1].rules[1].srcIP);
}

 void configuration::add(string sss){
    Policy pp;
    pp.name=sss;
    poli.push_back(pp);
    
 }

 base configuration::get(string ss,base bo){
    for(Policy po : poli){
        if(po.name==ss)
        {
            bo.rules=po.rules;
            return bo;
        }else{printf("pas de politique correspendante");}
    }
    }

    void configuration::add(){

    }

   /* base* configuration::get(){

    }*/

   void configuration::update(Rule rr,std::string nom){
        for(Policy po : poli){
        if(po.name==nom)
        {
            po.addRule(rr);
            
        }else{printf("pas de politique correspendante");}
    }
    }
   /* void configuration::set_sup_policy(Rule rr,string nom){
        for(Policy po : poli){
        if(po.name==nom)
        {
            po.;
            
        }else{printf("pas de politique correspendante");}
    }
    }*/