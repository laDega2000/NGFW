#include "interfaces.h"


interfaces::interfaces(){
    id=123;
   
   zone z;
   z.type="trust";
   this->zon=z;
  

}



void interfaces::send(char* packet){
    
}

packet interfaces::receive(int i){
   char errbuf[PCAP_ERRBUF_SIZE];
   pcap_t *handle = pcap_open_offline("pc.pcap", errbuf);
     struct pcap_pkthdr *header;
    const u_char *pack;
    int packet_count=0;
    int returnValue=1;
    while (packet_count < i)
    {
      returnValue = pcap_next_ex(handle, &header, &pack);
      if(returnValue==1)
      {
        packet_count++;
      }else if(returnValue==0){
        printf("fin du fichier");
        //pcap_close(handle);
        
      }

    }
    packet pak(pack);
    pak.src_zone.type=tt.is_zone(pak.src_ip);
    cout<<(pak.src_zone.type);
    pak.dst_zone.type=tt.is_zone(pak.dst_ip);
    cout<<(pak.dst_zone.type);
    return pak;
}










