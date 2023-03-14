#include "filtrage.h"

filtrage::filtrage() {}

strategieSEC* filtrage::get_strategy() {
    return new filtrage();
}

bool filtrage::execute(std::string srcIP, std::string destIP, int srcPort, int destPort, Policy& p, tabses& s) {
    if (s.isPacketInSession(srcIP, destIP, srcPort, destPort)) {
        printf("Paquet appartient déjà à une session.\n");
        return true;
    } else {
        bool ruleMatched = false;
        for (Rule r : p.rules) {
            if (srcIP == r.srcIP && destIP == r.destIP && srcPort == r.srcPort && destPort == r.destPort) {
                if (r.permit) {
                    printf("Paquet autorisé : règle correspondante.\n");
                    session se(srcIP, destIP, srcPort, destPort, "Etablie");
                    s.addSession(se);
                    return true;
                } else {
                    printf("Paquet rejeté : règle correspondante.\n");
                    return false;
                }
                ruleMatched = true;
                break;
            }
        }
        if (!ruleMatched) {
            printf("Paquet rejeté : aucune règle correspondante.\n");
            return false;
        }
    }
}
