#include "tabdomain.h"

tabdomain::tabdomain(/* args */)
{
     // Ouverture du fichier
    std::ifstream file("domain.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
    
    std::string domaine;
    

    // Récupération des sessions depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la session
        std::istringstream iss(line);
        
        //std::cout << "Ligne lue : " << line << std::endl;
        //std::cout << "Ligne lue : " << line << std::endl;
        if (iss >> domaine ) {
            // Création d'un nouvel objet session avec les attributs récupérés
            domain domain(domaine);
            // Ajout de la nouvelle session au vecteur sessions de la classe tabses
            domlist.push_back(domain);
        } else {
            std::cerr << "Error parsing session: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();
}

/*void tabdomain::add_domain(domain dom){
// Ouverture du fichier en mode "append"
    std::ofstream file("domain.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
     // Ajout de la nouvelle session à la fin du fichier
    file << dom.dom;
    this->domlist.push_back(dom);

    std::cout << "Nouvelle session créée" << std::endl;

    // Fermeture du fichier
    file.close();
}*/
bool tabdomain::is_domain(std::string d){
for (domain s : domlist) {
        if (s.dom == d ) {
            return true;
        }
    }
    return false;
}