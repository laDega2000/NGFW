#include "nat.h"
#include <iostream>

    nat::nat(){
    }

    std::string nat::route(packet pac,inter_conf* r,inter_conf* t){
         base b;
       for(tab_nat_stat ta :t->get_all(b).tab_n_statique){
        if(pac.src_ip==ta.ip_prive){
            std::cout<< "naté vers "<<ta.ip_public<< std::endl;
             // Modifier les adresses source et destination*

                    const char* src_addr_str = ta.ip_public.c_str();
               //memcpy(pac.pake + 6, src_addr_str, 6);
                
            return ta.ip_public;
        }
       }
       std::cout<<"naté par default"<<std::endl;
       
              // memcpy(pac.pake + 6, "192.168.1.1", 6);
       return "192.168.1.1";
    }
   