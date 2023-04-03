#include "interfaces.h"


interfaces::interfaces(){
    id=123;
   
   zone z;
   z.type="trust";
   this->zon=z;
  

}



void interfaces::send(char* packet){
    
}

const u_char * interfaces::receive(){
   char errbuf[PCAP_ERRBUF_SIZE];
   pcap_t *handle = pcap_open_offline("pc.pcap", errbuf);
     struct pcap_pkthdr *header;
    const u_char *packet;
   while (int returnValue = pcap_next_ex(handle, &header, &packet) >= 0) {
    if (returnValue == 0) continue;
     return packet;
    }
    return 0;
}










