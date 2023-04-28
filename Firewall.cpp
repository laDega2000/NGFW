#include <string>
#include <vector>
#include "Policy.h"
#include "tabses.h"
#include "Securite_Context.h"
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
#include "url_conf.h"
#include "zone_conf.h"
#include "base.h"
#include "groupe.h"

class Firewall
{
public:
    inter_conf* j;
    inter_conf* u_conf;
    inter_conf* z_conf;
    inter_conf* a_conf;
    tabses s;
    tabdomain tab;

    Firewall() {
      j=new configuration;;
     u_conf=new user_conf;
     z_conf=new zone_conf;
     a_conf=new url_conf;
      //this->j->add("dega");
    }
   



    void add_policy(base b){     // tu lui donne nom de la policy a ajouter et elle ajoute
           
        j->add(b.name_policy);
    }

    base get_policy(base b){    // elle retourne la policy corespendant au nom que ta donner
      b=j->get(b.name_policy,b);
      return b;
    }

    void add_rule(base b){ // tu dois donne un objet base avec dedant une rule et un b.name_policy
      j->update(b,b.name_policy);
    }

    void get_rule(){

      
    }

    void add_user_groupe(base b){    // tu lui donne nom du groupe a ajouter 
      u_conf->add(b.user_groupe_name);
    }

    void get_user(base b){   // tu lui donne non de user et elle retourne objet base avec interieur objet user
      u_conf->get(b.user_name,b);
    }

    void add_interface(){

    }


    void get_interface(){

    }


    void add_zone(base b){   // tu lui donne le type de la zone a ajouter
      z_conf->add(b.zone_name);
    }

    base get_zone(base b){    // tu lui donne le nom(type) de la zone et il te retourne un objet zone dans base
      z_conf->get(b.zone_name,b);
    }

    void add_route(){

    }

    void get_route(){

    }

    void add_nat(){

    }

    void get_nat(){

    }

    void add_aplication(base b){    // tu lui donne url et il ajoute
      a_conf->add(b.aplication_name);
    }

    base get_application_liste(base b){  // tu lui donne base il te rend urlliste dans base
      b.domaine_veu_liste=true;
      b=a_conf->get("ss",b);
      return b;
    }

    void add_session(){

    }

    void get_session(){

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
      packet pac(i.receive(x,u_conf));
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