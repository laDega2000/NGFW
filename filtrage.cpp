#include "filtrage.h"

filtrage::filtrage() {}

strategieSEC* filtrage::get_strategy() {
    return new filtrage();
}

bool filtrage::execute( packet pac, inter_conf* p,inter_conf* s,tabdomain &tab) {
    tools t;
       monitoring m;
       base bb;
       bool is;
    bb=s->get("rien",bb);
        for (session s : bb.tab_session) {
        if (s.src_ip == pac.src_ip && s.dst_ip == pac.dst_ip && s.src_port ==pac.src_port && s.dst_port == pac.dst_port) {
             is=true;
        }}
    
    
    if (is==true) {
        printf("Paquet appartient déjà à une session.\n");
        std::string deg=pac.src_ip;
        std::string s_log = "Packet accepted. Source IP: " + deg + " Destination IP: " + pac.dst_ip + ".";
        m.set_log("INFO", s_log);
        return true;
    } else {
       /// faire un appele a une fonction isFirstpacket
       
                                if(pac.isfirst==true||pac.isfirst==false)
                                {
                                 
                                    bool ruleMatched = false;
                                    //base pp=p->get("dega");
                                base bb;
                                    //bb.rules=pp->rules;
                                    for(Policy pp : p->get_all(bb).polit ){
                                    for (Rule r : pp.rules ){
                                       ruleMatched= (pac.src_ip == r.srcIP && pac.dst_ip == r.destIP && pac.src_port == r.srcPort && pac.dst_port == r.destPort); 
                                        if (ruleMatched==true){
                                            if (r.permit) {
                                                printf("Paquet autorisé : règle correspondante.\n");
                                                session se(pac.src_ip, pac.dst_ip, pac.src_port, pac.dst_port, "Etablie");
                                                
                                                bb.s=se;
                                                s->update(bb,"rien");
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
                                    }}
                                    if (!ruleMatched) {
                                        printf("Paquet rejeté : aucune règle correspondante.\n");
                                        std::string deg=pac.src_ip;
                                        std::string s_log = "Packet Rejeter. Source IP: " + deg + " Destination IP: " + pac.dst_ip + ".";
                                        m.set_log("WARNIING", s_log);
                                        return false;
                                    }
    } else {
         printf("Paquet rejeté : pas le premier de la sessison.\n");
             std::string deg=pac.src_ip;
            std::string s_log = "Packet Rejeter. Source IP: " + deg + " Destination IP: " + pac.dst_ip + ".";
             m.set_log("WARNIING", s_log);
            return false;
            }
    
    }
}