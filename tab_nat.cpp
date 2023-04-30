#include "tab_nat.h"

tab_nat::tab_nat()
{
     // Créer une nouvelle table de routage statique
     // Ouverture du fichier
    std::ifstream file("nat.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
        std::string prive, publi;
       
    // Récupération des règles depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la règle
        std::istringstream iss(line);
       
       // std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> prive >> publi ) {
            // Création d'un nouvel objet Rule avec les attributs récupérés
            tab_nat_stat ta;
            ta.ip_prive=prive;
            ta.ip_public=publi;
           //std::cout<< rule.destIP<<rule.destPort<<rule.srcIP;
            // Ajout de la nouvelle règle au vecteur rules de la classe Policy
            tabn.push_back(ta);
            //for (Rule r : rules) {
            //std::cout<<r.srcIP<<std::endl;
            //}
        } else {
            std::cerr << "Error parsing nat: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();
}

