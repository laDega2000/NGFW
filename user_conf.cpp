#include "user_conf.h"
#include <iostream>
    user_conf::user_conf(){
        groupe g;
        g.name="default";
        group.push_back(g);
    }

 base user_conf::get(string ss,base bo){
    bo.test=false;
    for(groupe po : group){
        for (user u : po.user_tab)
        {
        if(u.ip_adr==ss){
        
            bo.u=u;
            bo.test=true;
            return bo;
        }else{printf("pas de user correspendante");cout<<endl;bo.test=false;return bo;}
        }
        
        
    }
    }

    void user_conf::add(std::string ss){
            groupe pp;
            pp.name=ss;
            group.push_back(pp);
    }

   /* base* user_conf::get(){

    }*/
    
   void user_conf::update(base rr,std::string nom){
        std::vector<groupe>popo;
        groupe pipi;
        for(groupe po : group){
           
        if(po.name==nom)
        {
            
            
            pipi=po;
            pipi.add_user(rr.u);
            popo.push_back(pipi);
        }else{ popo.push_back(po);printf("pas de politique correspendante");cout<<endl;}
       
        }
         group.swap(popo);
    }
   /* void user_conf::set_sup_policy(Rule rr,string nom){
        for(Policy po : poli){
        if(po.name==nom)
        {
            po.;
            
        }else{printf("pas de politique correspendante");}
    }
    }*/