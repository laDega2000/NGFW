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
#include "configuration.h"
#include "inter_conf.h"
#include "base.h"
#include "groupe.h"

class Firewall
{
public:
    inter_conf* j;
    
    tabses s;
    tabdomain tab;

    Firewall() {
      
      //this->j->add("dega");
    }
   
    bool handle_incoming_packet(packet pac) {
         
        strategieSEC* obj=new filtrage;
        Securite_Context context;
        
        context.set_strategy(obj);
        this->j=new configuration;
       if (context.execute_strategy(pac,j, s,tab)==true) {
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
      bool var;
     // printf("ha nadkhol");

      while(true){
      packet pac(i.receive(x));
      //printf("jabtouuu");
      var=handle_incoming_packet(pac);
      x++;
      if(var==true)
      {
        strategieRTG* ob=new routage_stat;
        Routage_Context cont;
        tab_route r;
        tab_nat t;
        cont.set_strategy(ob);
        cont.execute_strategy(pac, r,t);
        ob=new nat;
        cont.set_strategy(ob);
        cont.execute_strategy(pac,r,t);
      }
      }
    }

    
    //void supr (string srcIP, string destIP, int srcPort, int destPort, bool permit){}
    
   


};