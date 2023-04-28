#include "url_conf.h"
#include <iostream>

url_conf::url_conf(/* args */){
   // Ouverture du fichier
    std::ifstream file("domain.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
         
        std::string zs;
    
    // Récupération des règles depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la règle
        std::istringstream iss(line);
       
       // std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> zs ) {
            // Création d'un nouvel objet Rule avec les attributs récupérés
            domain rule(zs);
           //std::cout<< rule.destIP<<rule.destPort<<rule.srcIP;
            // Ajout de la nouvelle règle au vecteur rules de la classe Policy
            domlist.push_back(rule);
            //for (Rule r : rules) {
            //std::cout<<r.srcIP<<std::endl;
            //}
        } else {
            std::cerr << "Error parsing domain: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();
 }

 base url_conf::get(string ss,base bo){
    if(bo.domaine_veu_liste==false){
    for(domain po : domlist){
        if(po.dom==ss)
        {
            bo.domaine=true;
            bo.domaine_url=po;
            return bo;
        }else{bo.domaine=false;("pas de domaine correspendante");}
    }}else{
        for(domain poo : domlist){
        
            bo.domaine_liste.push_back(poo);
           
            return bo;
        }

    }
    }

    void url_conf::add(std::string ss){
            domain pp(ss);
            
            domlist.push_back(pp);
    }



   void  url_conf::update(base rr,string nom){

    }


   /* base* url_conf::get(){

    }*/

   /*void url_conf::update(base rr,std::string nom){
        std::vector<Policy>popo;
        Policy pipi;
        for(Policy po : poli){
           
        if(po.name==nom)
        {
            
            
            pipi=po;
            pipi.addRule(rr.rul);
            popo.push_back(pipi);
        }else{ popo.push_back(po);;printf("pas de politique correspendante");}
        poli.swap(popo);
    }
    }
   /* void url_conf::set_sup_policy(Rule rr,string nom){
        for(Policy po : poli){
        if(po.name==nom)
        {
            po.;
            
        }else{printf("pas de politique correspendante");}
    }
    }*/