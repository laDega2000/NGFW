#include <netinet/ip.h>
#include <netinet/udp.h>
//#include "ltins"
#include <cstring>
#include <arpa/inet.h>
#include "strategieSEC.h"

class tools
{

public:
    tools();
    
    bool isDNSPacket( char* packet);
    bool isQuery( char* packet);
    char* extractDomainName(char* packet);
   // decapsule()
};


