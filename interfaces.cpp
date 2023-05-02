#include "interfaces.h"
interfaces::interfaces(){
    id=123;
   
   zone z;
   z.type="trust";
   this->zon=z;
  

}

interfaces::interfaces(int idd ,std::string zon){
  id=idd;
  this->zon.type=zon;
}

void interfaces::send(char* packet){
    
}

packet interfaces::receive(int i,inter_conf* ii){
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
    cout<<pak.src_ip<<" "<<pak.dst_ip<<" "<<pak.src_port<<" "<<pak.dst_port<<endl;
    pak.src_zone.type=tt.is_zone(pak.src_ip);
    cout<<(pak.src_zone.type)<<endl;
    pak.dst_zone.type=tt.is_zone(pak.dst_ip);
    cout<<(pak.dst_zone.type)<<endl;
    //ii =new user_conf;

    

    b=ii->get(pak.src_ip,b);

    if(b.test==true){pak.users=b.u;}

    /*else{cout<<"veuiller vous identifier"<<endl;cin>>pak.users.id >>pak.users.name;

      if(pak.users.id<5){pak.users.lev=admin;pak.users.sat=online;}
        b.u.ip_adr=pak.src_ip;
        b.u.id=pak.users.id;
        b.u.name=pak.users.name;
        b.u.zonn=pak.src_zone;
        ii->update(b,"default");
    
    }*/
    return pak;
}










