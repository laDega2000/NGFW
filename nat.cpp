#include "nat.h"
#include <iostream>

    nat::nat(){
    }

    std::string nat::route(packet pac,tab_route r,tab_nat t){
         
       for(tab_nat_stat ta :t.tabn){
        if(pac.src_ip==ta.ip_prive){
            std::cout<< "naté vers "<<ta.ip_public<< std::endl;
            return ta.ip_public;
        }
       }
       std::cout<<"naté par default"<<std::endl;
       return "192.168.1.1";
    }
   