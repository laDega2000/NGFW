#include "tabses.h"

tabses::tabses()
{
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
            sessions.push_back(session);
        } else {
            std::cerr << "Error parsing session: " << line << std::endl;
        }
    }

    // Fermeture du fichier
    file.close();
}

void tabses::addSession(session newSession) {
    // Ouverture du fichier en mode "append"
    std::ofstream file("session.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    // Ajout de la nouvelle session à la fin du fichier
    file << newSession.src_ip << " " << newSession.dst_ip << " "
         << newSession.src_port << " " << newSession.dst_port << " "
         << newSession.state << std::endl;
    sessions.push_back(newSession);

    std::cout << "Nouvelle session créée" << std::endl;

    // Fermeture du fichier
    file.close();
}

