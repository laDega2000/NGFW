#include "interfaces.h"


interfaces::interfaces(){
    id=123;
   
   zone z;
   z.type="trust";
   this->zon=z;
  

}



void interfaces::send(char* packet){
    
}

const u_char * interfaces::receive(int i){
   char errbuf[PCAP_ERRBUF_SIZE];
   pcap_t *handle = pcap_open_offline("pc.pcap", errbuf);
     struct pcap_pkthdr *header;
    const u_char *packet;
    int packet_count=0;
    int returnValue=1;
    while (packet_count < i)
    {
      returnValue = pcap_next_ex(handle, &header, &packet);
      if(returnValue==1)
      {
        packet_count++;
      }else if(returnValue==0){
        printf("fin du fichier");
        //pcap_close(handle);
        
      }

    }
    return packet;
}










