class PacketHandler {
public:
    PacketHandler(Firewall &firewall) : firewall(firewall) {}

    bool handle_incoming_packet(char *src_mac, int src_mac_len, char *packet, int packet_len) {
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
        if (firewall.filterPacket(src_ip, dst_ip, src_port, dst_port)) {
        printf("Packet accepted.\n");
        return true;
        } else {
        
        return false;
        }
        }

private:
Firewall &firewall;
};