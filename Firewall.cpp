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
#include "filtrurl.h"
//#include "strategieSEC.h"
class Firewall
{
public:
    Firewall() {}
   
    


    bool handle_incoming_packet(char *src_mac, int src_mac_len, char *packet, int packet_len,Policy& p,tabses& s) {
        


        

        strategieSEC* obj=new filtrurl;
        Securite_Context context;
        
        context.set_strategy(obj);
       if (context.execute_strategy(src_mac, src_mac_len,packet,  packet_len, p, s)) {
        printf("Packet accepted.\n");
        
        return true;
        }
         else {
       
            return false;
         }


        

        }
    //void supr (string srcIP, string destIP, int srcPort, int destPort, bool permit){}
    
   


};