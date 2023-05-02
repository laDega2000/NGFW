#include "Rule.h"

Rule::Rule(std::string u,std::string src_zoo,std::string dst_zoo,std::string srIP, std::string desIP, int srPort, int desPort, bool permi)
{
    src_zo=src_zoo;
    dst_zo=dst_zoo;
    srcPort = srPort;
    destPort = desPort;
    permit = permi;
    srcIP = srIP;
    destIP = desIP;
    us.name=u;
}

Rule::Rule(){
    
}