#include <iostream>
#include <vector>
#include <string>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include "Firewall.cpp"

int main(int argc, char *argv[]) {

//printf("maiiin");
Firewall fire;
//printf("ha nadba nadkhol");
fire.get_packet();
    

return 0;
}