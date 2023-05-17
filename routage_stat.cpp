#include "routage_stat.h"
#include <iostream>

    routage_stat::routage_stat(){
    }

    packet routage_stat::route(packet pac,inter_conf* r,inter_conf* t){
        base b;
        b=r->get("rien",b);
       for(tab_stat ta :b.tab_r_statique){
        if(pac.dst_ip==ta.adr_dest){
            std::cout<< "routé vers "<<ta.next_hop<< std::endl;
            pac.next_hop=ta.next_hop;
                return pac;
        }
       }
       std::cout<<"routé par default"<<std::endl;
       pac.next_hop="192.168.1.1";
       return pac;
    }
   