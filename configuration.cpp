#include "configuration.h"
#include <iostream>
configuration::configuration(/* args */){
   /*Policy pa;
    this->add("dega");
    Rule r("192.168.1.2", "192.168.1.255", 137, 137 ,true);
    
    this->update(r,"dega");
   //std::cout<<(this->poli[1].rules[1].srcIP);
}

 void configuration::add(string sss){
    Policy pp;
    pp.name=sss;
    poli.push_back(pp);
    */
 Policy pp;
  this->add("dega");
  base bb;
          bb.rul.srcIP=("192.168.1.2");
          bb.rul.destIP=("192.168.1.1");
          bb.rul.srcPort=2832;
          bb.rul.destPort=53;
          bb.rul.permit=true;
  
         this->update(bb,"dega");

         this->add("zone");
         base bbb;
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

    void configuration::add(std::string ss){
            Policy pp;
            pp.name=ss;
            poli.push_back(pp);
    }

   /* base* configuration::get(){

    }*/

   void configuration::update(base rr,std::string nom){
        std::vector<Policy>popo;
        Policy pipi;
        for(Policy po : poli){
           
        if(po.name==nom)
        {
            
            
            pipi=po;
            pipi.addRule(rr.rul);
            popo.push_back(pipi);
        }else{ popo.push_back(po);;printf("pas de politique correspendante");}
        poli.swap(popo);
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