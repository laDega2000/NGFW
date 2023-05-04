#include "packet.h"


packet::packet(){}
packet::packet(const u_char* pack) {
    
    pake= const_cast<u_char*>(pack);
    
    char* output = const_cast<char*>(reinterpret_cast<const char*>(pack));
    char *ip_packet = output  + sizeof(struct ether_header);
    struct iphdr *iph = (struct iphdr *) ip_packet;
    char *tcp_packet = ip_packet + (iph->ihl * 4);
    struct tcphdr *tcph = (struct tcphdr *) tcp_packet;

    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &iph->saddr, src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &iph->daddr, dst_ip, INET_ADDRSTRLEN);
    int src_port = ntohs(tcph->source);
    int dst_port = ntohs(tcph->dest);

    this->src_ip = src_ip;
    this->dst_ip = dst_ip;
    this->src_port = src_port;
    this->dst_port = dst_port;


        this->isfirst=false;

            ack=tcph->ack_seq;
            syn=tcph->seq;
            window=tcph->window;
            sum=tcph->th_sum;
            flag=tcph->th_flags;
            
        //check si c'est le premier 
        // Obtenir l'en-tête IP et TCP du paquet
    const u_char* ip_header = pack + sizeof(struct ether_header);
    u_int16_t ip_header_length = (*ip_header & 0xF) * 4;
    const u_char* tcp_header = ip_header + ip_header_length;
    u_int16_t tcp_header_length = (*(tcp_header + 12) >> 4) * 4;

    // Obtenir les drapeaux TCP du paquet
    bool syn_flag = *(tcp_header + 13) & 0x02; 
    bool ack_flag = *(tcp_header + 13) & 0x10;
       
    // Vérifier que le paquet est le premier de la session TCP

    if ((syn_flag==true) && (ack_flag==false)) {
        this->isfirst= true;
    } else if ((syn_flag==true) && (ack_flag==true)) {
        u_int32_t seq_num = ntohl(*(u_int32_t*)(tcp_header + 4));
        if (seq_num == 0) {
           this->isfirst=  true;
        }
    }
   





    // Check if the packet is an HTTP packet
    if (src_port == 80 || dst_port == 80) {
        char* http_data = tcp_packet + (tcph->doff * 4);
        int data_length = ntohs(iph->tot_len) - (iph->ihl * 4) - (tcph->doff * 4);

        // Look for end of HTTP header (double CRLF)
        char* http_end = strstr(http_data, "\r\n\r\n");
        if (http_end != NULL) {
            int header_length = http_end - http_data + 4;
            int payload_length = data_length - header_length;



            // Allocate memory for header and payload
            this->header = new char[header_length + 1];
            this->header[header_length] = '\0';
            this->payload = new char[payload_length + 1];
            this->payload[payload_length] = '\0';

            // Copy data into header and payload
            strncpy(this->header, http_data, header_length);
            strncpy(this->payload, http_data + header_length, payload_length);
        }
    }
}