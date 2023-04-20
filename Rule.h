#ifndef RULE_H
#define RULE_H

#include <string>

class Rule {
public:
    std::string srcIP;
    std::string src_zo;
    std::string dst_zo;
    std::string destIP;
    int srcPort;
    int destPort;
    bool permit;
    Rule();
    Rule(std::string src_zo,std::string dst_zo,std::string srIP, std::string desIP, int srPort, int desPort, bool permi);

    /*void deleteRule(string srcIP, string destIP, int srcPort, int destPort) {
        for (auto it = rules.begin(); it != rules.end(); ++it) {
            if (it->srcIP == srcIP && it->destIP == destIP && it->srcPort == srcPort && it->destPort == destPort) {
                rules.erase(it);
                break;
            }
        }
    }*/
};

#endif
