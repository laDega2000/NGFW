#include "routage_stat.h"
#include <iostream>

    routage_stat::routage_stat(){
    }

    std::string routage_stat::route(packet pac,inter_conf* r,tab_nat t){
        base b;
        b=r->get("rien",b);
       for(tab_stat ta :b.tab_r_statique){
        if(pac.dst_ip==ta.adr_dest){
            std::cout<< "routé vers "<<ta.next_hop<< std::endl;
            return ta.next_hop;
        }
       }
       std::cout<<"routé par default";
       return "192.168.1.1";
    }
   