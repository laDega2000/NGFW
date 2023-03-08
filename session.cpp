 #include <string>
 #include <vector>
 #include<iostream>
 #include <sstream> // nécessaire pour utiliser std::istringstream
#include <fstream> // nécessaire pour lire un fichier
class session
{
public:
    std::string src_ip;
    std::string dst_ip;
    int src_port;
    int dst_port;
    std::string state;
    std::vector<session> sessions;
    session::session(std::string src_ip, std::string dst_ip, int src_port, int dst_port, std::string state)
    {
            this->src_port=src_port;
            this->dst_port=dst_port;
            this->state=state;
            this->src_ip=src_ip;
            this->dst_ip=dst_ip;
    }
    session::session()
    {
         // Ouverture du fichier
    std::ifstream file("session.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
        std::string srcIP, state,destIP;
        int srcPort, destPort;
        
    // Récupération des règles depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la règle
        std::istringstream iss(line);
       
        std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> srcIP >> destIP >> srcPort >> destPort >> state) {
            // Création d'un nouvel objet Rule avec les attributs récupérés
            session session(srcIP,destIP,srcPort ,destPort,state);
           //std::cout<< rule.destIP<<rule.destPort<<rule.srcIP;
            // Ajout de la nouvelle règle au vecteur rules de la classe Policy
            sessions.push_back(session);
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
       
};

