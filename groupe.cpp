#include "groupe.h"

#include <iostream>
groupe::groupe(/* args */)
{
     // Ouverture du fichier
    std::ifstream file("groupe.txt");
    if (!file.is_open()) {
        cerr << "Error opening file" << std::endl;
        return;
    }
         
         int id;
    std::string name;
    // Récupération des règles depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la règle
        std::istringstream iss(line);
       
       // std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> id >> name) {
            // Création d'un nouvel objet Rule avec les attributs récupérés
            user u;
            u.id=id;
            u.name=name;
            u.lev=admin;
            u.sat=online;
            u.zonn.type="trust";
           //std::cout<< rule.destIP<<rule.destPort<<rule.srcIP;
            // Ajout de la nouvelle règle au vecteur rules de la classe Policy
            user_tab.push_back(u);
            //for (Rule r : rules) {
            //std::cout<<r.srcIP<<std::endl;
            //}
        } else {
            cerr << "Error parsing user: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();
}

 void groupe::add_user(user u){
    user_tab.push_back(u);
 }

    user groupe::get_user(string name){
        for (user uu : user_tab )
        {
            if(uu.name==name)return uu;
        }
        
    }