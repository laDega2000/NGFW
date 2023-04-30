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
      //this->j->add("dega");

      packet_filter_thread_ = std::thread([this]() {
       get_packet();
    });
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

    void get_user(base b){   // tu lui donne non de user et elle retourne objet base avec interieur objet user
      u_conf->get(b.user_name,b);
    }



    void addUser(const std::vector<std::string>& params) {
    if (params.size() == 2) {
        string g_name = (params[0]);
        string u_name = params[1];

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
 


    void showUser(const std::vector<std::string>& params) {
    if (params.size() == 1) {
        int id = std::stoi(params[0]);
        get_all_user();
        // Use the variable to perform the required action
        //std::cout << "Showing user with id: " << id << std::endl;

    } else {
        std::cout << "Invalid number of parameters for showUser command." << std::endl;
        std::cout << "Expected usage: showUser id" << std::endl;
        std::cout << "Parameters:" << std::endl;
        std::cout << "  id: The user ID to be shown (integer)" << std::endl;
    }
}


    void get_all_user(){
        base b;
       b= u_conf->get_all(b);
         
            for(user u : b.tab_use)
            {
                std::cout<< u.name<<endl;
            }
        
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

    void add_route(base b){
      r_conf->update(b,"rien");
    }

    base get_route(){
      base b;
        b=r_conf->get("rien",b);
        return b;
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

    void add_session(base b){
        s_conf->update(b,"rien");
    }

    void get_session(){
        base b;
        s_conf->get("rien",b);
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
        tab_nat t;
        cont.set_strategy(ob);
        cont.execute_strategy(pac, r_conf,t);
        ob=new nat;
        cont.set_strategy(ob);
        cont.execute_strategy(pac,r_conf,t);
      }
      }
      if(x==10){x=1;}
    }

    
    //void supr (string srcIP, string destIP, int srcPort, int destPort, bool permit){}
    
   



















void run_cli() {
    // Command map
    std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> command_map = {
        {"add_policy", std::bind(&Firewall::add_policy, this, std::placeholders::_1)},
        {"show_all_policy", std::bind(&Firewall::show_all_policy, this, std::placeholders::_1)},
        {"add_rule_in_policy", std::bind(&Firewall::add_rule_in_policy, this, std::placeholders::_1)},
        {"addUser", std::bind(&Firewall::addUser, this, std::placeholders::_1)},
        {"showUser", std::bind(&Firewall::showUser, this, std::placeholders::_1)},
       // {"delete_policy", std::bind(&Firewall::delete_policy, this, std::placeholders::_1)},
       
        /*{"show_policy", std::bind(&Firewall::show_policy, this, std::placeholders::_1)},
       
        {"delete_rule_from_policy", std::bind(&Firewall::delete_rule_from_policy, this, std::placeholders::_1)},
        
        {"deleteUser", std::bind(&Firewall::deleteUser, this, std::placeholders::_1)},
        {"updateUser", std::bind(&Firewall::updateUser, this, std::placeholders::_1)},
        
        {"addInterface", std::bind(&Firewall::addInterface, this, std::placeholders::_1)},

        {"deleteInterface", std::bind(&Firewall::deleteInterface, this, std::placeholders::_1)},
        {"updateInterface", std::bind(&Firewall::updateInterface, this, std::placeholders::_1)},
        {"showInterface", std::bind(&Firewall::showInterface, this, std::placeholders::_1)},
        {"addSession", std::bind(&Firewall::addSession, this, std::placeholders::_1)},
        {"updateSession", std::bind(&Firewall::updateSession, this, std::placeholders::_1)},
        {"showSession", std::bind(&Firewall::showSession, this, std::placeholders::_1)},
        {"deleteSession", std::bind(&Firewall::deleteSession, this, std::placeholders::_1)},
        {"addZone", std::bind(&Firewall::addZone, this, std::placeholders::_1)},
        {"updateZone", std::bind(&Firewall::updateZone, this, std::placeholders::_1)},
        {"showZone", std::bind(&Firewall::showZone, this, std::placeholders::_1)},
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