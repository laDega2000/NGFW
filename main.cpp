#include <iostream>
#include <vector>

#include <string>

#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include "Firewall.cpp"






int main(int argc, char *argv[]) {


Firewall fire;
fire.get_packet();
    

return 0;
}