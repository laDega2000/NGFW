#include "zone_conf.h"
#include <iostream>


    zone_conf::zone_conf(){
        zone z;
        z.type="trust";
        this->zoo.push_back(z);
         zone zz;
        zz.type="untrust";
        this->zoo.push_back(zz);
         zone zzz;
        zzz.type="DMZ";
        this->zoo.push_back(zzz);
    }

    base zone_conf::get(string ss,base bo){
    for(zone po : zoo){
        if(po.type==ss)
        {
            bo.zi=po;
            return bo;
        }else{printf("pas de zone correspendante");}
    }
    }

    void zone_conf::add(std::string ss){
            zone pp;
            pp.type=ss;
            zoo.push_back(pp);
    }
base zone_conf::get_all(base b){}

   void zone_conf::update(base rr,std::string nom){
        
    }
    
   /* void zone_conf::set_sup_policy(Rule rr,string nom){
       
    }*/