#include "session_conf.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
session_conf::session_conf(/* args */){
   // Ouverture du fichier
    std::ifstream file("session.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    
    std::string srcIP, state, destIP;
    int srcPort, destPort;

    // Récupération des sessions depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la session
        std::istringstream iss(line);
        
       // std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> srcIP >> destIP >> srcPort >> destPort >> state) {
            // Création d'un nouvel objet session avec les attributs récupérés
            session session(srcIP, destIP, srcPort, destPort, state);
            // Ajout de la nouvelle session au vecteur sessions de la classe tabses
            ses_tab.push_back(session);
        } else {
            std::cerr << "Error parsing session: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();
 }

 base session_conf::get(string ss,base bo){
    for(session po : ses_tab){
        
        bo.tab_session.push_back(po);
           
    }return bo;
    }

    void session_conf::add(std::string ss){
           
    }

   /* base* session_conf::get(){

    }*/

   void session_conf::update(base rr,std::string nom){
       
            
            ses_tab.push_back(rr.s);
    }
   /* void session_conf::set_sup_session(Rule rr,string nom){
        for(session po : ses_tab){
        if(po.name==nom)
        {
            po.;
            
        }else{printf("pas de ses_tabtique correspendante");}
    }
    }*/