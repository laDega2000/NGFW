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
#include "nat.h"
#include "nat_conf.h"
#include "in_conf.h"
#include "user_conf.h"
#include "configuration.h"
#include "inter_conf.h"
#include "url_conf.h"
#include "zone_conf.h"
#include "base.h"
#include "session_conf.h"
#include "groupe.h"
#include "route_conf.h"
#include <thread>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <functional>
#include <regex>
#include <iterator>


using namespace std;

class Firewall
{
public:
    inter_conf* j;
    inter_conf* u_conf;
    inter_conf* z_conf;
    inter_conf* a_conf;
    inter_conf* s_conf;
    inter_conf* r_conf;
    inter_conf* n_conf;
    inter_conf* i_conf;
    tabses s;
    tabdomain tab;
    std::thread packet_filter_thread_;

    Firewall(int argc, char *argv[]) {
      j=new configuration;
     u_conf=new user_conf;
     z_conf=new zone_conf;
     a_conf=new url_conf;
     s_conf=new session_conf;
     r_conf=new route_conf;
     n_conf=new nat_conf;
     i_conf=new in_conf;
      //this->j->add("dega");

      
    }
   



    void addd_policy(base b){     // tu lui donne nom de la policy a ajouter et elle ajoute
           
        j->add(b.name_policy);
    }


 void add_policy(const std::vector<std::string>& params) {
    if (params.size() == 1) {
        std::string name = params[0];
      base  b;
      b.name_policy=params[0];
      this->addd_policy(b);
        // Use the variable to perform the required action
        std::cout << "Adding policy with name: " << name << std::endl;

    } else {
        std::cout << "Invalid number of parameters for add_policy command." << std::endl;
        std::cout << "Expected usage: add_policy name" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  name: The policy name to be added" << std::endl;
    }
}



void show_all_policy(const std::vector<std::string>& params) {
    if (params.empty()) {
        // Perform the required action to display all policies
        //std::cout << "Displaying all policies..." << std::endl;
        show_policy();
    } else {
        std::cout << "Invalid number of parameters for show_all_policy command." << std::endl;
        std::cout << "Expected usage: show_all_policy" << std::endl;
    }
}
// show_policy


    base get_policy(base b){    // elle retourne la policy corespendant au nom que ta donner
      b=j->get(b.name_policy,b);
      return b;
    }

   void show_policy(){
      base b;
     // b=j->get_all(b);

      for(Policy pp: j->get_all(b).polit){
      
        cout<<pp.name<<endl;
        for(Rule r : pp.rules){
          cout<<r.srcIP<<" "<<r.destIP<<" "<<r.srcPort<<" "<<r.destPort<<" "<< r.src_zo<<" " << r.dst_zo<<" "<<r.permit<<endl;
        }
      }
    }


  // add_rule_in_policy
void add_rule_in_policy(const std::vector<std::string>& params) {
    if (params.size() == 9) {
        std::string rule_name = params[0];
        base b;


        
        b.rul.src_zo=params[1];
        b.rul.src_zo=params[2];
        b.rul.srcIP=params[3];
        b.rul.destIP=params[4];
        b.rul.srcPort=std::stoi(params[5]);
        b.rul.destPort=std::stoi(params[6]);
        b.rul.us.name=params[7];
        if(params[8]=="true")
        {
          b.rul.permit=true;
        }else if(params[8]=="false")b.rul.permit=false;
        
        
        
        
        b.name_policy=params[0];
        add_rule(b);
        // Use the rule_name variable to perform the required action
        std::cout << "Adding rule "<< " in policy" <<params[0]<< std::endl;

    } else {
        std::cout << "Invalid number of parameters for add_rule_in_policy command." << std::endl;
        std::cout << "Expected usage: add_rule_in_policy nameRule" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  nameRule: The name of the rule to be added in the policy" << std::endl;
    }
}




    void add_rule(base b){ // tu dois donne un objet base avec dedant une rule et un b.name_policy
      j->update(b,b.name_policy);
    }

    void get_rule(){

      
    }

    void add_user_groupe(base b){    // tu lui donne nom du groupe a ajouter 
      u_conf->add(b.user_groupe_name);
    }


    void addgroupe(const std::vector<std::string>& params) {
    if (params.size() == 1) {
        string g_name = (params[0]);
        base b;b.user_groupe_name=g_name;
        add_user_groupe(b);

      /* std::string name = params[1];
        int lev = std::stoi(params[2]);
        int sat = std::stoi(params[3]);
        std::string ip_adr = params[4];
        std::string mac = params[5];
        int zonn = std::stoi(params[6]);*/

        // Use the variables to perform the required action
        //std::cout << "Adding user with id: " << id << ", name: " << name << ", lev: " << lev << ", sat: " << sat
          //        << ", ip_adr: " << ip_adr << ", mac: " << mac << ", zonn: " << zonn << std::endl;

    } else {
        std::cout << "Invalid number of parameters for addUser command." << std::endl;
        std::cout << "Expected usage: addUser id name lev sat ip_adr mac zonn" << std::endl;
       
    }
}

    void get_user(base b){   // tu lui donne non de user et elle retourne objet base avec interieur objet user
      u_conf->get(b.user_name,b);
    }



    void addUser(const std::vector<std::string>& params) {
    if (params.size() == 2) {
        string g_name = (params[0]);
        string u_name = params[1];
        add_user_in_group(u_name,g_name);
      /* std::string name = params[1];
        int lev = std::stoi(params[2]);
        int sat = std::stoi(params[3]);
        std::string ip_adr = params[4];
        std::string mac = params[5];
        int zonn = std::stoi(params[6]);*/

        // Use the variables to perform the required action
        //std::cout << "Adding user with id: " << id << ", name: " << name << ", lev: " << lev << ", sat: " << sat
          //        << ", ip_adr: " << ip_adr << ", mac: " << mac << ", zonn: " << zonn << std::endl;

    } else {
        std::cout << "Invalid number of parameters for addUser command." << std::endl;
        std::cout << "Expected usage: addUser id name lev sat ip_adr mac zonn" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The user ID (integer)" << std::endl;
        std::cout << "  name: The user name" << std::endl;
        std::cout << "  lev: The user level (integer)" << std::endl;
        std::cout << "  sat: The user satisfaction (integer)" << std::endl;
        std::cout << "  ip_adr: The user IP address" << std::endl;
        std::cout << "  mac: The user MAC address" << std::endl;
        std::cout << "  zonn: The user zone (integer)" << std::endl;
    }
}




    void add_user_in_group(string u_name,string g_name){
      base b;
      b.user_groupe_name=g_name;
      b.user_name=u_name;
      u_conf->update(b,b.user_groupe_name);
    }
 

//const std::vector<std::string>& params
    void showUser() {
      get_all_user(false);
      }
   

    void showgroupe(){
      get_all_user(true);
    }

    void get_all_user(bool type){
        base b;
       //b= u_conf->get_all(b);
         if(type==false){
            for(user ub : u_conf->get_all(b).tab_use)
            {
                cout<<ub.group<<" "<< ub.name <<endl;
                
            }
         }else{
          for(groupe po : u_conf->get_all(b).tab_groupe){
            cout<<po.name<<endl;
          }
         }
    }



    void addInterface(const std::vector<std::string>& params) {
    if (params.size() == 4) {
        //int id = std::stoi(params[0]);
        std::string file = params[0];
        std::string out = params[1];
        std::string ip = params[2];
        std::string zone = params[3];

        // Use the variables to perform the required action
        std::cout << "Adding interfaces: " <<ip<<endl;
        interfaces i(file.c_str(),out.c_str(),ip,zone);
        add_interface(i);

    } else {
        std::cout << "Invalid number of parameters for addInterface command." << std::endl;
        std::cout << "Expected usage: addInterface id base inter_conf tools zone" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The interface ID (integer)" << std::endl;
        std::cout << "  base: The base configuration" << std::endl;
        std::cout << "  inter_conf: The interface configuration" << std::endl;
        std::cout << "  tools: The tools used for the interface" << std::endl;
        std::cout << "  zone: The zone of the interface" << std::endl;
    }
}



    void add_interface(interfaces i){
        base bi;
        bi.interf=i;
        i_conf->update(bi,"rien");
    }


    void get_interface(){
      base bi;
        bi=i_conf->get_all(bi);
        for(interfaces f : bi.tab_interfaces){
          cout<<f.file_name<<" "<<f.ip_adr<<endl;
        }
    }

    void showInterface(const std::vector<std::string>& params) {
    if (params.size() == 1) {
       // int id = std::stoi(params[0]);

        // Use the variable to perform the required action
        std::cout << "Showing interfaces " << std::endl;
        get_interface();

    } else {
        std::cout << "Invalid number of parameters for showInterface command." << std::endl;
        std::cout << "Expected usage: showInterface id" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The interface ID to be shown (integer)" << std::endl;
    }
}


    void addZone(const std::vector<std::string>& params) {
    if (params.size() == 1) {
      
        std::string type = params[0];

        // Use the variables to perform the required action
        std::cout << "Adding zone with id: " << " type: " << type << std::endl;
        base bo;
        bo.zone_name=type;
        add_zone(bo);
    } else {
        std::cout << "Invalid number of parameters for addZone command." << std::endl;
        std::cout << "Expected usage: addZone id type" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The zone ID (integer)" << std::endl;
        std::cout << "  type: The zone type" << std::endl;
    }
}





    void add_zone(base bo){   // tu lui donne le type de la zone a ajouter
      z_conf->add(bo.zone_name);
    }


    void showZone(const std::vector<std::string>& params) {
    if (params.size() == 1) {
        int id = std::stoi(params[0]);

        // Use the variable to perform the required action
        //std::cout << "Showing zone with id: " << id << std::endl;
          get_zone();

    } else {
        std::cout << "Invalid number of parameters for showZone command." << std::endl;
        std::cout << "Expected usage: showZone id" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The zone ID to be shown (integer)" << std::endl;
    }
}



    base get_zone(){    // tu lui donne le nom(type) de la zone et il te retourne un objet zone dans base
      base bbbb;
      bbbb=z_conf->get_all(bbbb);
      for(zone z : bbbb.zii){
        cout<<z.type<<endl;
      }
    }







    void addroute(const std::vector<std::string>& params) {
    if (params.size() == 2) {
        //int id = std::stoi(params[0]);
        std::string publicIp = params[0];
        std::string privateIp = params[1];
        base br;
        br.r_statique.adr_dest=publicIp;
        br.r_statique.next_hop=privateIp;
        // Use the variables to perform the required action
        std::cout << "Adding route  "  << ", destinationIp: " << publicIp << ", next_hop: " << privateIp << std::endl;
        add_route(br);
    } else {
        std::cout << "Invalid number of parameters for addroute command." << std::endl;
        std::cout << "Expected usage: addNat id destnationIP nexthop" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The route ID (integer)" << std::endl;
        std::cout << "  destionationIP: The public IP address" << std::endl;
        std::cout << "  nexthop: The private IP address" << std::endl;
    }
}













    void add_route(base b){
      r_conf->update(b,"rien");
    }

    void get_route(){
      base brr;
        
        for(tab_stat rt : r_conf->get_all(brr).tab_r_statique){
            cout<<rt.adr_dest<<" "<<rt.next_hop<<endl;
        }
    }





    void show_route(const std::vector<std::string>& params) {
    if (params.size() == 1) {
        //int id = std::stoi(params[0]);

        // Use the variable to perform the required action
        std::cout << "Showing route "<< std::endl;
        get_route();
    } else {
        std::cout << "Invalid number of parameters for showNat command." << std::endl;
        std::cout << "Expected usage: showroute id" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The route ID to be shown (integer)" << std::endl;
    }
}




    void addNat(const std::vector<std::string>& params) {
    if (params.size() == 2) {
        //int id = std::stoi(params[0]);
        std::string publicIp = params[0];
        std::string privateIp = params[1];

        // Use the variables to perform the required action
        std::cout << "Adding NAT " << ", publicIp: " << publicIp << ", privateIp: " << privateIp << std::endl;
        base bn;
        bn.n_statique.ip_public=publicIp;
        bn.n_statique.ip_prive=privateIp;
        add_nat(bn);  
    } else {
        std::cout << "Invalid number of parameters for addNat command." << std::endl;
        std::cout << "Expected usage: addNat id publicIp privateIp" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The NAT ID (integer)" << std::endl;
        std::cout << "  publicIp: The public IP address" << std::endl;
        std::cout << "  privateIp: The private IP address" << std::endl;
    }
}





    void add_nat(base bn){
      
        n_conf->update(bn,"rien");
    }

    void get_nat(){
      base bnn;
      
      for(tab_nat_stat o : n_conf->get_all(bnn).tab_n_statique){
        cout<<o.ip_prive<<" "<<o.ip_public<<endl;
      }
    }





    void showNat(const std::vector<std::string>& params) {
    if (params.size() == 1) {
        //int id = std::stoi(params[0]);

        // Use the variable to perform the required action
        std::cout << "Showing NAT "  << std::endl;
          get_nat();
    } else {
        std::cout << "Invalid number of parameters for showNat command." << std::endl;
        std::cout << "Expected usage: showNat id" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The NAT ID to be shown (integer)" << std::endl;
    }
}

        

    // Create functions for all other commands
    // ...

    void help(const std::vector<std::string>& params) {
        // Your implementation
    }






    void add_aplication(base b){    // tu lui donne url et il ajoute
      a_conf->add(b.aplication_name);
    }

    base get_application_liste(base b){  // tu lui donne base il te rend urlliste dans base
      b.domaine_veu_liste=true;
      b=a_conf->get("ss",b);
      return b;
    }



  void addSession(const std::vector<std::string>& params) {
    if (params.size() == 5) {
        std::string src_ip = params[0];
        std::string dst_ip = params[1];
        int src_port = std::stoi(params[2]);
        int dst_port = std::stoi(params[3]);
        std::string state = params[4];

        // Use the variables to perform the required action
        base b;
        b.s.src_ip=src_ip;
        b.s.dst_ip=dst_ip;
        b.s.src_port=src_port;
        b.s.dst_port=dst_port;
        b.s.state=state;
        add_session(b);
        std::cout << "Adding session with src_ip: " << src_ip << ", dst_ip: " << dst_ip << ", src_port: " << src_port
                  << ", dst_port: " << dst_port << ", state: " << state << std::endl;

    } else {
        std::cout << "Invalid number of parameters for addSession command." << std::endl;
        std::cout << "Expected usage: addSession src_ip dst_ip src_port dst_port state" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  src_ip: The source IP address" << std::endl;
        std::cout << "  dst_ip: The destination IP address" << std::endl;
        std::cout << "  src_port: The source port (integer)" << std::endl;
        std::cout << "  dst_port: The destination port (integer)" << std::endl;
        std::cout << "  state: The session state" << std::endl;
    }
}


    void add_session(base b){
        s_conf->update(b,"rien");
    }

    base get_session(){
        base b;
        return s_conf->get_all(b);
    }


  void showSession(const std::vector<std::string>& params) {
    if (params.size() == 1) {
        int id = std::stoi(params[0]);

        // Use the variable to perform the required action
       
        std::cout << "Showing session with id: " << id << std::endl;
         base bb=get_session();
         for(session po : bb.tab_session){
            
                std::cout<<po.src_ip<<" "<<po.dst_ip<<" "<<po.src_port<<" "<<po.dst_port<<" "<<po.state<<endl;
            
        }
    } else {
         std::cout << "Invalid number of parameters for showSession command." << std::endl;
        std::cout << "Expected usage: showSession id" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The session ID to be shown (integer)" << std::endl;
    }
}






    bool handle_incoming_packet(packet pac) {
         
        strategieSEC* obj=new filtrage;
        Securite_Context context;
        
        context.set_strategy(obj);
        this->j=new configuration;
       if (context.execute_strategy(pac,j, s_conf,tab)==true) {
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
      std::regex regx("^(192\\.168\\.)[0-9]+\\.[0-9]+$");
      int x=1;
      strategieRTG* ob;
      packet pac;
      strategieRTG* obb;
      bool var;
      Routage_Context cont;
      Routage_Context out;
      packet pipipi;
     // printf("ha nadkhol");
     base bi;
    
      
  while(true){
      for(interfaces i : i_conf->get_all(bi).tab_interfaces){
         while(x<20){
            pac=i.receive(x);
            

            // aucun nat
            if(std::regex_match(pac.dst_ip,regx)==true && (std::regex_match(pac.src_ip,regx)==true)){
                    var=handle_incoming_packet(pac);

            x++;
            if(var==true)
            {
              
             ob=new routage_stat;
            
            cont.set_strategy(ob);
              
              
              pac=cont.execute_strategy(pac, r_conf,n_conf);
              /*ob=new nat;
              cont.set_strategy(ob);
              pac=cont.execute_strategy(pac,r_conf,n_conf);*/
              i.send(pac);
              
            }
            }
            else{
                        //paquet entrant  destination
                  if(std::regex_match(pac.dst_ip,regx)==true && (std::regex_match(pac.src_ip,regx)==false)){
                      pac.entre=false;
                     /* obb=new nat;
                    
                    out.set_strategy(obb);
                    packet poop;
                    poop=out.execute_strategy(pac,r_conf,n_conf);
                    pac.dst_ip=poop.dst_ip;
                    pac.dst_port=poop.dst_port;*/
                      var=handle_incoming_packet(pac);

                    x++;
                    if(var==true)                                                                      // sbab l'adresse ta3 khraaaaaaaaaaaaaaaaaaaaaaaa
                    {
                      
                    ob=new routage_stat;
                    
                    cont.set_strategy(ob);
                      
                      
                      pipipi=cont.execute_strategy(pac, r_conf,n_conf);
                      /*ob=new nat;
                      cont.set_strategy(ob);
                      pac=cont.execute_strategy(pac,r_conf,n_conf);*/
                      i.send(pac);
                      
                    }
                    }
                   else {               // paquet sortant nat source
                                      if(std::regex_match(pac.dst_ip,regx)==false && (std::regex_match(pac.src_ip,regx))==true){
                                        
                                              pac.entre=true;
                                            
                                            
                                            
                                            //pac=cont.execute_strategy(pac,r_conf,n_conf);
                                            //printf("jabtouuu");
                                            //pac.entre=false;
                                            var=handle_incoming_packet(pac);

                                            x++;
                                            if(var==true)
                                            {
                                              
                                            ob=new routage_stat;
                                            
                                            cont.set_strategy(ob);
                                              
                                              
                                              pac=cont.execute_strategy(pac, r_conf,n_conf);
                                              ob=new nat;
                                              cont.set_strategy(ob);
                                              pac=cont.execute_strategy(pac,r_conf,n_conf);
                                              i.send(pac);
                                              
                                            }
                                      }
                                      else{
                                         if(std::regex_match(pac.dst_ip,regx)==false && (std::regex_match(pac.src_ip,regx)==false)){
                                                pac.entre=false;
                                               obb=new nat;
                                              
                                              out.set_strategy(obb);
                                              packet poop;
                                              poop=out.execute_strategy(pac,r_conf,n_conf);
                                              pac.dst_ip=poop.dst_ip;
                                              pac.dst_port=poop.dst_port;
                                                var=handle_incoming_packet(pac);

                                              x++;
                                              if(var==true)
                                              {
                                                
                                              ob=new routage_stat;
                                              
                                              cont.set_strategy(ob);
                                                
                                                
                                                pac=cont.execute_strategy(pac, r_conf,n_conf);
                                                /*ob=new nat;
                                                cont.set_strategy(ob);
                                                pac=cont.execute_strategy(pac,r_conf,n_conf);*/
                                                i.send(pac);
                                                
                                              }
                                              }
                                      }
                          }
            }
          }x=1;}
     
     
 //}
  }
  }
    //void supr (string srcIP, string destIP, int srcPort, int destPort, bool permit){}
    
   



















void run_cli() {
    // Command map
    std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> command_map = {
        {"add_policy", std::bind(&Firewall::add_policy, this, std::placeholders::_1)},
        {"show_all_policy", std::bind(&Firewall::show_all_policy, this, std::placeholders::_1)},
        {"add_rule_in_policy", std::bind(&Firewall::add_rule_in_policy, this, std::placeholders::_1)},
        {"add_user", std::bind(&Firewall::addUser, this, std::placeholders::_1)},
        {"add_groupe", std::bind(&Firewall::addgroupe, this, std::placeholders::_1)},
        {"show_user", std::bind(&Firewall::showUser, this)},
         {"show_groupe", std::bind(&Firewall::showgroupe, this)},
        {"add_session", std::bind(&Firewall::addSession, this, std::placeholders::_1)},
        {"show_session", std::bind(&Firewall::showSession, this, std::placeholders::_1)},
        {"add_zone", std::bind(&Firewall::addZone, this, std::placeholders::_1)},
        {"show_zone", std::bind(&Firewall::showZone, this, std::placeholders::_1)},
        {"add_route", std::bind(&Firewall::addroute, this, std::placeholders::_1)},
        {"show_route", std::bind(&Firewall::show_route, this, std::placeholders::_1)},
        {"add_nat", std::bind(&Firewall::addNat, this, std::placeholders::_1)},
        {"show_nat", std::bind(&Firewall::showNat, this, std::placeholders::_1)},
        {"add_interface", std::bind(&Firewall::addInterface, this, std::placeholders::_1)},
         {"show_interface", std::bind(&Firewall::showInterface, this, std::placeholders::_1)},
       // {"delete_policy", std::bind(&Firewall::delete_policy, this, std::placeholders::_1)},
       
        /*{"show_policy", std::bind(&Firewall::show_policy, this, std::placeholders::_1)},
       
        {"delete_rule_from_policy", std::bind(&Firewall::delete_rule_from_policy, this, std::placeholders::_1)},
        
        {"deleteUser", std::bind(&Firewall::deleteUser, this, std::placeholders::_1)},
        {"updateUser", std::bind(&Firewall::updateUser, this, std::placeholders::_1)},
        
        

        {"deleteInterface", std::bind(&Firewall::deleteInterface, this, std::placeholders::_1)},
        {"updateInterface", std::bind(&Firewall::updateInterface, this, std::placeholders::_1)},
       
        
        {"updateSession", std::bind(&Firewall::updateSession, this, std::placeholders::_1)},
        
        {"deleteSession", std::bind(&Firewall::deleteSession, this, std::placeholders::_1)},
        {"addZone", std::bind(&Firewall::addZone, this, std::placeholders::_1)},
        
        {"deleteZone", std::bind(&Firewall::deleteZone, this, std::placeholders::_1)},
        {"addNat", std::bind(&Firewall::addNat, this, std::placeholders::_1)},
        {"updateNat", std::bind(&Firewall::updateNat, this, std::placeholders::_1)},
        {"showNat", std::bind(&Firewall::showNat, this, std::placeholders::_1)},
        {"help", std::bind(&Firewall::help, this, std::placeholders::_1)}*/
    };

    // Boucle de commande CLI
    while (true) {
        // Affiche le prompt de commande
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);

        // Tokenize the input
        std::istringstream iss(input);
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};

        // Check if the command is in the map
        if (!tokens.empty()) {
            auto cmd = command_map.find(tokens[0]);
            if (cmd != command_map.end()) {
                // Extract the parameters
                std::vector<std::string> params(tokens.begin() + 1, tokens.end());

                // Call the command handler
                cmd->second(params);
            } else {
                std::cout << "Command not recognized.\n";
            }
        }
    }
}












};