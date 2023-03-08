#include <vector>
#include<iostream>
#include "Rule.cpp"
#include <sstream> // nécessaire pour utiliser std::istringstream
#include <fstream> // nécessaire pour lire un fichier

class Policy
{

public:
   std::vector<Rule> rules;

    Policy() {
    // Ouverture du fichier
    std::ifstream file("rules.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }
        std::string srcIP, destIP;
        int srcPort, destPort;
        bool permit;
    // Récupération des règles depuis un fichier
    std::string line;
    while (std::getline(file, line)) {
        // Analyse la ligne pour récupérer les attributs de la règle
        std::istringstream iss(line);
       
        std::cout << "Ligne lue : " << line << std::endl;

        if (iss >> srcIP >> destIP >> srcPort >> destPort >> std::boolalpha >> permit) {
            // Création d'un nouvel objet Rule avec les attributs récupérés
            Rule rule(srcIP,destIP,srcPort ,destPort,permit);
           //std::cout<< rule.destIP<<rule.destPort<<rule.srcIP;
            // Ajout de la nouvelle règle au vecteur rules de la classe Policy
            rules.push_back(rule);
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


 void addRule(Rule r) {
        
        Policy p;
        p.rules.push_back(r);
    }
};


