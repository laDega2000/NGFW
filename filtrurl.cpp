#include "filtrurl.h"

filtrurl::filtrurl() {}





bool filtrurl::execute(char *src_mac, int src_mac_len, char *packet, int packet_len, Policy& p, tabses& s,tabdomain& tab) {
    tools t;
    Log m;
    tabdomain tabb;
    if (t.isDNSPacket(packet)) {
      //  if (t.isQuery(packet)) {
            //printf("je suis dns");
            char* domainName = t.extractDomainName(packet);
            printf(domainName);
            // Faites quelque chose avec le nom de domaine ici
            if(tabb.is_domain(domainName)){
            printf("paquet rejeter");
            return false;
            }
            else{
                 printf("Paquet accepter : Nom de Domain  autoriser.\n");
                     std::string deg=domainName;
                      std::string s_log = "Packet Rejeter. Domain: " + deg+  ".";
                     m.writeLog("WARNIING", s_log);
                    return true;
                    
            }
            //delete[] domainName; // N'oubliez pas de libérer la mémoire allouée !
       // }
       // else return false;
    }else{
        printf("je ne suis pas dns"); 
        return false;
    }

}