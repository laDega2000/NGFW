#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include "Firewall.cpp"




int main(int argc, char *argv[]) {
if (argc < 2) {
printf("Usage: %s <pcap_file>\n", argv[0]);
return 1;
}
char errbuf[PCAP_ERRBUF_SIZE];
pcap_t *handle = pcap_open_offline(argv[1], errbuf);
if (!handle) {
    printf("pcap_open_offline() failed: %s\n", errbuf);
    return 1;
}

Firewall firewall;

struct pcap_pkthdr *header;
const u_char *packet;

while (int returnValue = pcap_next_ex(handle, &header, &packet) >= 0) {
    if (returnValue == 0) continue;
    if (firewall.handle_incoming_packet((char *) packet, header->len, (char *) packet, header->len)) {
        // packet is allowed
    } else {
        // packet is dropped
    }
}

return 0;
}