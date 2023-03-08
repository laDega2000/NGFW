 #include <string>
 #include <vector>

class Rule {
    
  
    public:
    std::string srcIP;
    std::string destIP;
    int srcPort;
    int destPort;
    bool permit;

   
    
   Rule(std::string srIP, std::string desIP, int srPort, int desPort,  bool permi)
         {
            srcPort=srPort;
            destPort=desPort;
            permit=permi;
            srcIP=srIP;
            destIP=desIP;
         }

   
    /*void deleteRule(string srcIP, string destIP, int srcPort, int destPort) {
        for (auto it = rules.begin(); it != rules.end(); ++it) {
            if (it->srcIP == srcIP && it->destIP == destIP && it->srcPort == srcPort && it->destPort == destPort) {
                rules.erase(it);
                break;
            }
        }
    }*/

};


