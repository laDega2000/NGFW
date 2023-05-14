#include "interfaces.h"
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
interfaces::interfaces(){
    id=123;
   zone z;
   z.type="trust";
   this->zon=z;
  

}



interfaces::interfaces(const char* filename,const char* output_name ,string ip,std::string zon){
  
  this->zon.type=zon;
  this->file_name=filename;
  this->output=output_name;
  this->ip_adr=ip;
}


void interfaces::send(packet pkt) {
 /* // Ouverture du fichier
    ofstream myfile;
  myfile.open ("capture.pcap");
  myfile << "\n";
  myfile.close();*/


   char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    int packet_count = 1;

    // Ouvrir le fichier .pcap pour l'enregistrement
    handle = pcap_open_dead(DLT_EN10MB, 65535);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_dead() failed: %s\n", pcap_geterr(handle));
        return;
    }

    // Créer un fichier .pcap pour l'enregistrement
    pcap_dumper_t *dumper = pcap_dump_open_append(handle, this->output);
    if (dumper == NULL) {
        fprintf(stderr, "pcap_dump_open() failed: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return;
    }

       



    // Construire un paquet
    uint8_t packet_data[] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, // adresse MAC source (à remplacer)
        0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, // adresse MAC destination (à remplacer)
        0x08, 0x00,                         // type de protocole (IPv4)
        0x45, 0x00, 0x00, 0x1c,             // en-tête IPv4 (version, longueur, type de service, longueur totale)
        0x00, 0x00, 0x40, 0x00,             // en-tête IPv4 (identificateur, drapeaux, décalage de fragment)
        0x40, 0x06, 0xb8, 0x1e,             // en-tête IPv4 (temps de vie, protocole, somme de contrôle en-tête)
        0x00, 0x00, 0x00, 0x00,             // adresse IP source (à remplacer)
        0x00, 0x00, 0x00, 0x00,             // adresse IP destination (à remplacer)
        0x00, 0x00,                         // port source (à remplacer)
        0x00, 0x00,                          // port destination (à remplacer)
        0x00, 0x00, 0x00, 0x00,             // en-tête TCP (numéro de séquence)
        0x00, 0x00, 0x00, 0x00,             // en-tête TCP (numéro d'acknowledgment)
        0x50, 0x02, 0xff, 0xff,             // en-tête TCP (longueur de l'en-tête et flags)
        0x00, 0x00, 0x00, 0x00,             // en-tête TCP (window size)
        0x00, 0x00, 0x00, 0x00,             // en-tête TCP (checksum)
        0x00, 0x00,                          // en-tête TCP (urgent pointer)
        0x48, 0x65, 0x6c, 0x6c,             // données TCP (Hello World)
        0x6f, 0x20, 0x57, 0x6f,
        0x72, 0x6c, 0x64
    };


    // Remplir les champs des en-têtes
    header.ts.tv_sec = time(NULL);
    header.ts.tv_usec = 0;
    header.len = sizeof(packet_data);
    header.caplen = sizeof(packet_data);
  // Convertir les adresses MAC de chaînes de caractères en format binaire
const char *src_mac_str = pkt.src_mac.c_str();
const char *dst_mac_str = pkt.dst_mac.c_str();
uint8_t src_mac[6], dst_mac[6];
sscanf(src_mac_str, "%02x:%02x:%02x:%02x:%02x:%02x", &src_mac[0], &src_mac[1], &src_mac[2], &src_mac[3], &src_mac[4], &src_mac[5]);
sscanf(dst_mac_str, "%02x:%02x:%02x:%02x:%02x:%02x", &dst_mac[0], &dst_mac[1], &dst_mac[2], &dst_mac[3], &dst_mac[4], &dst_mac[5]);



  //  string s;s=reverse(pkt.src_ip);
    //string ss;ss=reverse(pkt.dst_ip);
 // Convertir les adresses IP de chaînes de caractères en format binaire
    const char *src_ip_str = pkt.src_ip.c_str();
    const char *dst_ip_str = pkt.dst_ip.c_str();
    in_addr_t src_ip, dst_ip;
    inet_pton(AF_INET, src_ip_str, &src_ip);
    inet_pton(AF_INET, dst_ip_str, &dst_ip);


// Insérer les adresses MAC dans le paquet
memcpy(&packet_data[0], src_mac, 6); // adresse MAC source
memcpy(&packet_data[6], dst_mac, 6); // adresse MAC destination
uint16_t src_port = htons(pkt.src_port);
uint16_t dst_port = htons(pkt.dst_port);

// Insérer les adresses IP et les ports dans le paquet

memcpy(&packet_data[26], &src_ip, sizeof(src_ip)); // adresse IP source
memcpy(&packet_data[30], &dst_ip, sizeof(dst_ip)); // adresse IP destination
memcpy(&packet_data[34], &src_port, sizeof(src_port)); // port source
memcpy(&packet_data[36], &dst_port, sizeof(dst_port)); // port destination
memcpy(&packet_data[38], &pkt.syn, sizeof(pkt.syn)); // syn
memcpy(&packet_data[42], &pkt.ack, sizeof(pkt.ack)); // ack
memcpy(&packet_data[46], &pkt.flag, sizeof(pkt.flag)); // sum et flag
memcpy(&packet_data[47], &pkt.window, sizeof(pkt.window)); // window
memcpy(&packet_data[51], &pkt.sum, sizeof(pkt.sum)); // window
// Enregistrer le paquet dans le fichier .pcap
pcap_dump((u_char *) dumper, &header, packet_data);

// Fermer le fichier .pcap
pcap_dump_close(dumper);
pcap_close(handle);
    
    
}





packet interfaces::receive(int i){
   char errbuf[PCAP_ERRBUF_SIZE];
   pcap_t *handle = pcap_open_offline(file_name, errbuf);
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
    pak.heade=header;
     
    


    cout<<pak.src_ip<<" "<<pak.dst_ip<<" "<<pak.src_port<<" "<<pak.dst_port<<endl;
    pak.src_zone.type=tt.is_zone(pak.src_ip);
    //cout<<(pak.src_zone.type)<<endl;
    pak.dst_zone.type=tt.is_zone(pak.dst_ip);
    //cout<<(pak.dst_zone.type)<<endl;
    //ii =new user_conf;

    

   // bab=ii->get(pak.src_ip,bab);

   // if(bab.test==true){pak.users=bab.u;}

    /*else{cout<<"veuiller vous identifier"<<endl;cin>>pak.users.id >>pak.users.name;

      if(pak.users.id<5){pak.users.lev=admin;pak.users.sat=online;}
        b.u.ip_adr=pak.src_ip;
        b.u.id=pak.users.id;
        b.u.name=pak.users.name;
        b.u.zonn=pak.src_zone;
        ii->update(b,"default");
    
    }*/
    pak.isfirst=true;
    return pak;
}










