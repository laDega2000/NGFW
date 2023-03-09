#include "session.cpp"
class tabses
{

public:
    std::vector<session> sessions;

    tabses()
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

    void addSession(session newSession) {
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
    printf("nouvelle session crée");
    // Fermeture du fichier
    //file.close();
    }

    bool isPacketInSession(std::string srcIP, std::string destIP, int srcPort, int destPort)
    {
    for (session s : sessions) {
        if (s.src_ip == srcIP && s.dst_ip == destIP && s.src_port == srcPort && s.dst_port == destPort) {
            return true;
        }
    }
    return false;
}


};


