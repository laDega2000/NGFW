#include "filtrage.h"

bool filtrage::execute(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy p, tabses s) {
    if(s.isPacketInSession(srcIP, destIP, srcPort, destPort)) {
        printf("Paquet appartient déjà à une session.\n");
        return true;
    } else {
        for (Rule r : p.rules) {
            if (srcIP == r.srcIP && destIP == r.destIP && srcPort == r.srcPort && destPort == r.destPort && r.permit) {
                printf("Paquet autorisé : règle correspondante.\n");
                session se(srcIP, destIP, srcPort, destPort, "Etablie");
                s.addSession(se);
                return true;
            } else if (srcIP == r.srcIP && destIP == r.destIP && srcPort == r.srcPort && destPort == r.destPort && !r.permit) {
                printf("Paquet rejeté : règle correspondante.\n");
                return false;
            } else {
                printf("Paquet rejeté : aucune règle correspondante.\n");
                return false;
            }
        }
        return false;
    }
}
