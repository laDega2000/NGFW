#include "nat.h"
#include <iostream>

    nat::nat(){
    }

    std::string nat::route(char *src_mac, int src_mac_len, char *packet, int packet_len,tab_route r,tab_nat t){
         char *ip_packet = packet  + sizeof(struct ether_header);
        struct iphdr *iph = (struct iphdr *) ip_packet;
        char *tcp_packet = ip_packet + (iph->ihl * 4);
        struct tcphdr *tcph = (struct tcphdr *) tcp_packet;

        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &iph->saddr, src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &iph->daddr, dst_ip, INET_ADDRSTRLEN);
        int src_port = ntohs(tcph->source);
        int dst_port = ntohs(tcph->dest);
     // std::cout<<src_ip<<std::endl<< dst_ip<<std::endl<< src_port<<std::endl<< dst_port<<std::endl;
       for(tab_nat_stat ta :t.tabn){
        if(src_ip==ta.ip_prive){
            std::cout<< "naté vers "<<ta.ip_public<< std::endl;
            return ta.ip_public;
        }
       }
       std::cout<<"naté par default"<<std::endl;
       return "192.168.1.1";
    }
   