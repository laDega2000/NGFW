#include <string>
#include <vector>
#include "Policy.h"
#include "tabses.h"
#include "Securite_Context.h"
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <pcap.h>
#include "filtrage.h"
//#include "strategieSEC.h"
class Firewall
{
public:
    Firewall() {}
   
    


    bool handle_incoming_packet(char *src_mac, int src_mac_len, char *packet, int packet_len,Policy p,tabses s) {
        char *ip_packet = packet + src_mac_len + sizeof(struct ether_header);
        struct iphdr *iph = (struct iphdr *) ip_packet;
        char *tcp_packet = ip_packet + (iph->ihl * 4);
        struct tcphdr *tcph = (struct tcphdr *) tcp_packet;

        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &iph->saddr, src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &iph->daddr, dst_ip, INET_ADDRSTRLEN);
        int src_port = ntohs(tcph->source);
        int dst_port = ntohs(tcph->dest);
       std::cout<<src_ip<<std::endl<< dst_ip<<std::endl<< src_port<<std::endl<< dst_port<<std::endl;




        strategieSEC* obj=new filtrage;
        Securite_Context context;
        
        context.set_strategy(obj);
        if (context.execute_strategy(src_ip, dst_ip, src_port, dst_port,p,s)) {
        printf("Packet accepted.\n");
        return true;
        } else {
        
        return false;
        }
        }
    //void supr (string srcIP, string destIP, int srcPort, int destPort, bool permit){}
    
   


};