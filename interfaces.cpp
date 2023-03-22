#include "interfaces.h"


interfaces::interfaces(){
    id=123;
   Firewall firewal;
   this->firewall=firewal;

}



void interfaces::send(char* packet){
    
}

void interfaces::receive(const u_char* packet,pcap_pkthdr *header){
   
   
    
     firewall.handle_incoming_packet((char *) packet, header->len, (char *) packet, header->len);
        // packet is allowed
        
    
        // packet is dropped
    
}