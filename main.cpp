#include <iostream>
#include <vector>
#include <string>
#include "Firewall.cpp"

int main(int argc, char *argv[]) {

//printf("maiiin");
//Firewall fire;
//printf("ha nadba nadkhol");
//fire.get_packet();
    
 // Create the firewall object
    Firewall firewall(argc, argv);
    firewall.packet_filter_thread_ = std::thread([&firewall]() {
       firewall.get_packet();
    });
    // Run the CLI in a separate thread
    std::thread cli_thread(&Firewall::run_cli, &firewall);

    // Wait for the CLI thread to finish
    cli_thread.join();

    return 0;
return 0;
}