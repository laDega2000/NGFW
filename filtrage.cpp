#include "filtrage.h"

filtrage::filtrage() {}

strategieSEC* filtrage::get_strategy() {
    return new filtrage();
}

bool filtrage::execute(char *src_mac, int src_mac_len, char *packet, int packet_len, Policy& p, tabses& s) {
    char *ip_packet = packet + src_mac_len + sizeof(struct ether_header);
        struct iphdr *iph = (struct iphdr *) ip_packet;
        char *tcp_packet = ip_packet + (iph->ihl * 4);
        struct tcphdr *tcph = (struct tcphdr *) tcp_packet;

        char src_ip[INET_ADDRSTRLEN];
        char dst_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &iph->saddr, src_ip, INET_ADDRSTRLEN);
        inet_ntop(AF_INET, &iph->daddr, dst_ip, INET_ADDRSTRLEN);
        int src_port = ntohs(tcph->source);
        int dst_port = ntohs(tcph->dest);
       std::cout<<src_ip<<std::endl<< dst_ip<<std::endl<< src_port<<std::endl<< dst_port<<std::endl;
       monitoring m;

    if (s.isPacketInSession(src_ip, dst_ip, src_port, dst_port)) {
        printf("Paquet appartient déjà à une session.\n");
        std::string deg=src_ip;
        std::string s_log = "Packet accepted. Source IP: " + deg + " Destination IP: " + dst_ip + ".";
        m.set_log("INFO", s_log);
        return true;
    } else {
        bool ruleMatched = false;
        for (Rule r : p.rules) {
            if (src_ip == r.srcIP && dst_ip == r.destIP && src_port == r.srcPort && dst_port == r.destPort) {
                if (r.permit) {
                    printf("Paquet autorisé : règle correspondante.\n");
                    session se(src_ip, dst_ip, src_port, dst_port, "Etablie");
                    s.addSession(se);
                    std::string deg=src_ip;
                    std::string s_log = "Packet accepted. Source IP: " + deg + " Destination IP: " + dst_ip + ".";
                     m.set_log("INFO", s_log);
                    return true;
                } else {
                    printf("Paquet rejeté : règle correspondante.\n");
                     std::string deg=src_ip;
                      std::string s_log = "Packet Rejeter. Source IP: " + deg + " Destination IP: " + dst_ip + ".";
                     m.set_log("WARNIING", s_log);
                    return false;
                }
                ruleMatched = true;
                break;
            }
        }
        if (!ruleMatched) {
            printf("Paquet rejeté : aucune règle correspondante.\n");
             std::string deg=src_ip;
            std::string s_log = "Packet Rejeter. Source IP: " + deg + " Destination IP: " + dst_ip + ".";
             m.set_log("WARNIING", s_log);
            return false;
        }
    }
}
