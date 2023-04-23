#include "tab_route.h"

tab_route::tab_route()
{
     // Créer une nouvelle table de routage statique
     // Ouverture du fichier
    std::ifstream file("stat.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
        std::string dst, next;
       
    // Récupération des règles depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la règle
        std::istringstream iss(line);
       
       // std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> dst >> next ) {
            // Création d'un nouvel objet Rule avec les attributs récupérés
            tab_stat tabb;
            tabb.adr_dest=dst;
            tabb.next_hop=next;
           //std::cout<< rule.destIP<<rule.destPort<<rule.srcIP;
            // Ajout de la nouvelle règle au vecteur rules de la classe Policy
            stat.push_back(tabb);
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

