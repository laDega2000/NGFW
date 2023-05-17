#include "configuration.h"
#include <iostream>
#include <fstream>
#include <sstream>
configuration::configuration(/* args */){



    Policy pp;
  this->add("dega");
  base bb;
          bb.rul.srcIP=("217.168.1.2");
          bb.rul.destIP=("192.168.1.255");
          bb.rul.srcPort=137;
          bb.rul.destPort=137;
          bb.rul.permit=true;
          bb.rul.dst_zo="trust";
          bb.rul.src_zo="untrust";
          bb.rul.us.name="ANY";
  
         this->update(bb,"dega");

        this->add("zone");
         base bbb;
   //Ouverture du fichier
    std::ifstream file("rules.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    
    std::string srcIP, state, destIP;
    std::string src_zon,dst_zon;
    user uu;
    int srcPort, destPort;

    // Récupération des sessions depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la session
        std::istringstream iss(line);
        
       // std::cout << "Ligne lue : " << line << std::endl;

        if (iss >>src_zon >>dst_zon >> srcIP >> destIP >> srcPort >> destPort>> uu.name>> state) {
            // Création d'un nouvel objet session avec les attributs récupérés
            Rule rule;
            rule.src_zo=src_zon;rule.dst_zo=dst_zon;rule.srcIP=srcIP;rule.destIP=destIP;rule.srcPort=srcPort;rule.destPort=destPort;rule.us.name=uu.name;rule.permit=true;
            // Ajout de la nouvelle session au vecteur sessions de la classe tabses
            base bbb;
            bbb.rul=rule;
           this->update(bbb,"zone");
        } else {
            std::cerr << "Error parsing session: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();












 
 }

 base configuration::get(string ss,base bo){
    for(Policy po : poli){
        if(po.name==ss)
        {
            bo.rules=po.rules;
            return bo;
        }else{printf("pas de politique correspendante");}
    }
    }

    void configuration::add(std::string ss){
            Policy pp;
            pp.name=ss;
            poli.push_back(pp);
    }




    base configuration::get_all(base b){
        for(Policy po : poli){
            b.polit.push_back(po);
        }return b;
    }


   /* base* configuration::get(){

    }*/

   void configuration::update(base rr,std::string nom){
        std::vector<Policy>popo;
        Policy pipi;
        for(Policy po : poli){
           
        if(po.name==nom)
        {
            
            
            pipi=po;
            pipi.addRule(rr.rul);
            popo.push_back(pipi);
        }else{ popo.push_back(po);}
        poli.swap(popo);
    }
    }
   /* void configuration::set_sup_policy(Rule rr,string nom){
        for(Policy po : poli){
        if(po.name==nom)
        {
            po.;
            
        }else{printf("pas de politique correspendante");}
    }
    }*/