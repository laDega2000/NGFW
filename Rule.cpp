#include "Rule.h"

Rule::Rule(std::string srIP, std::string desIP, int srPort, int desPort, bool permi)
{
    srcPort = srPort;
    destPort = desPort;
    permit = permi;
    srcIP = srIP;
    destIP = desIP;
}
