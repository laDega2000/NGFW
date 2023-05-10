#include  "aplication_tab.h"
#include <iostream>
#include <sstream> // nécessaire pour utiliser std::istringstream
#include <fstream> // nécessaire pour lire un fichier
aplication_tab::aplication_tab(/* args */)
{
     // Ouverture du fichier
    std::ifstream file("application.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
         
        std::string name;
        
    // Récupération des règles depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la règle
        std::istringstream iss(line);
       
       // std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> name ) {
            // Création d'un nouvel objet Rule avec les attributs récupérés
            aplication app(name);
           //std::cout<< rule.destIP<<rule.destPort<<rule.srcIP;
            // Ajout de la nouvelle règle au vecteur rules de la classe Policy
            app_tab.push_back(app);
            //for (Rule r : rules) {
            //std::cout<<r.srcIP<<std::endl;
            //}
        } else {
            std::cerr << "Error parsing rule: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();
}

