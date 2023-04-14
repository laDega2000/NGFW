#include "routage_stat.h"
#include <iostream>

    routage_stat::routage_stat(){
    }

    std::string routage_stat::route(packet pac,tab_route r,tab_nat t){
        
       for(tab_stat ta :r.stat){
        if(pac.dst_ip==ta.adr_dest){
            std::cout<< "routé vers "<<ta.next_hop<< std::endl;
            return ta.next_hop;
        }
       }
       std::cout<<"routé par default";
       return "192.168.1.1";
    }
   