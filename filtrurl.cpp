#include "filtrurl.h"

filtrurl::filtrurl() {}





bool filtrurl::execute(char *src_mac, int src_mac_len, char *packet, int packet_len, Policy& p, tabses& s) {
    tools t;
    if (t.isDNSPacket(packet)) {
        if (t.isQuery(packet)) {
            char* domainName = t.extractDomainName(packet);
            // Faites quelque chose avec le nom de domaine ici
            delete[] domainName; // N'oubliez pas de libérer la mémoire allouée !
        }
    }
}