#include "filtrage.h"

filtrage::filtrage() {}

strategieSEC* filtrage::get_strategy() {
    return new filtrage();
}

bool filtrage::execute( packet pac, inter_conf* p, tabses& s,tabdomain &tab) {
    
       monitoring m;
    
    if (s.isPacketInSession(pac.src_ip,pac.dst_ip,pac.src_port, pac.dst_port)) {
        printf("Paquet appartient déjà à une session.\n");
        std::string deg=pac.src_ip;
        std::string s_log = "Packet accepted. Source IP: " + deg + " Destination IP: " + pac.dst_ip + ".";
        m.set_log("INFO", s_log);
        return true;
    } else {
       
        bool ruleMatched = false;
        //base pp=p->get("dega");
       base bb;
        //bb.rules=pp->rules;
        for (Rule r : p->get("dega",bb).rules) {
            if (((pac.src_zone.type==r.src_zo)&&(pac.dst_zone.type==r.dst_zo))||((pac.src_ip == r.srcIP || pac.src_ip=="ANY") && (pac.dst_ip == r.destIP || pac.dst_ip=="ANY") && (pac.src_port == r.srcPort) && (pac.dst_port == r.destPort) && (pac.users.name== r.us.name||pac.users.name=="ANY"))) {
                if (r.permit) {
                    printf("Paquet autorisé : règle correspondante.\n");
                    session se(pac.src_ip, pac.dst_ip, pac.src_port, pac.dst_port, "Etablie");
                    s.addSession(se);
                    std::string deg=pac.src_ip;
                    std::string s_log = "Packet accepted. Source IP: " + deg + " Destination IP: " + pac.dst_ip + ".";
                     m.set_log("INFO", s_log);
                    return true;
                } else {
                    printf("Paquet rejeté : règle correspondante.\n");
                     std::string deg=pac.src_ip;
                      std::string s_log = "Packet Rejeter. Source IP: " + deg + " Destination IP: " + pac.dst_ip + ".";
                     m.set_log("WARNIING", s_log);
                    return false;
                }
                ruleMatched = true;
                break;
            }
        }
        if (!ruleMatched) {
            printf("Paquet rejeté : aucune règle correspondante.\n");
             std::string deg=pac.src_ip;
            std::string s_log = "Packet Rejeter. Source IP: " + deg + " Destination IP: " + pac.dst_ip + ".";
             m.set_log("WARNIING", s_log);
            return false;
        }
    }
    
}
