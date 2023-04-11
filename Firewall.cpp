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
#include "tabdomain.h"
#include "interfaces.h"
#include "Routage_Context.h"
#include "routage_stat.h"
#include "tab_route.h"
#include "nat.h"
class Firewall
{
public:
     Policy p;
    tabses s;
    tabdomain tab;
    Firewall() {}
   
    bool handle_incoming_packet(char *packet, int packet_len) {
        
        strategieSEC* obj=new filtrage;
        Securite_Context context;
        
        context.set_strategy(obj);
       if (context.execute_strategy(packet,  packet_len, p, s,tab)==true) {
           // printf("Packet accepted.\n");
           return true;
        }
         else {
            //printf("Packet rejected.\n");
            return false;
          }

    }



    void get_packet(){
      //printf("bdiit");

      struct pcap_pkthdr *header;
      interfaces i;
      int x=1;
      const u_char* packet;
      bool var;
     // printf("ha nadkhol");

      while(true){
      packet=i.receive(x);
      //printf("jabtouuu");
      var=handle_incoming_packet((char *) packet, header->len);
      x++;
      if(var==true)
      {
        strategieRTG* ob=new routage_stat;
        Routage_Context cont;
        tab_route r;
        tab_nat t;
        cont.set_strategy(ob);
        cont.execute_strategy((char *) packet, header->len, (char *) packet, header->len, r,t);
        ob=new nat;
        cont.set_strategy(ob);
        cont.execute_strategy((char *) packet, header->len, (char *) packet, header->len, r,t);
      }
      }
    }

    
    //void supr (string srcIP, string destIP, int srcPort, int destPort, bool permit){}
    
   


};