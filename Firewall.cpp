#include <string>
#include <vector>
#include "Policy.cpp"
#include "tabses.cpp"
class Firewall
{
public:
    Firewall() {}
   
    Policy p;
    tabses s;
    //void supr (string srcIP, string destIP, int srcPort, int destPort, bool permit){}
    
    bool filterPacket(std::string srcIP, std::string destIP, int srcPort, int destPort) {
        
        if(s.isPacketInSession(srcIP,destIP,srcPort,destPort))
        {
            printf("paquet apartien deja a une session");
            return true;
        }else{
        for (Rule r : p.rules) {
            if (srcIP == r.srcIP && destIP == r.destIP && srcPort == r.srcPort && destPort == r.destPort && r.permit==true) {
                printf("Packet allowed: rule matched.\n");
                session se(srcIP,destIP,srcPort,destPort,"Etablie");

                s.addSession(se);
                return true;
            }
            else if (srcIP == r.srcIP && destIP == r.destIP && srcPort == r.srcPort && destPort == r.destPort && r.permit==false) {
                printf("Packet dropped: rule matched.\n");
                return false;
            }else{
                printf("Packet dropped: no matching rule.\n");
                return false;
            }
        }
        return 0;
    }
    }


};