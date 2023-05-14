#include "nat.h"
#include <iostream>

    nat::nat(){
        Translation t;
        t.original_ip="192.168.1.1";
        t.original_port=217;
        t.translated_ip="6.6.6.6";
        t.translated_port=218;
        nat_translation.push_back(t);
       
    }

    packet nat::route(packet pac,inter_conf* r,inter_conf* t){
         /*base b;
       for(tab_nat_stat ta :t->get_all(b).tab_n_statique){
        if(pac.src_ip==ta.ip_prive){
            std::cout<< "naté vers "<<ta.ip_public<< std::endl;
             // Modifier les adresses source et destination*

                    const char* src_addr_str = ta.ip_public.c_str();
               //memcpy(pac.pake + 6, src_addr_str, 6);
                
            return ta.ip_public;
        }
       }
       std::cout<<"naté par default"<<std::endl;
       
              // memcpy(pac.pake + 6, "192.168.1.1", 6);
       return "192.168.1.1";*/
      return nat_bidirectionnel(pac);
    }
   

    // Génère une nouvelle adresse IP publique
std::string nat::get_new_public_ip() {
    // Code de génération d'une adresse IP publique
    // Par exemple, vous pouvez utiliser une bibliothèque de génération d'adresses IP ou simplement retourner une valeur prédéfinie à des fins de démonstration
    // Dans cet exemple, nous retournerons une adresse IP aléatoire entre 192.0.2.0 et 192.0.2.255
   srand(static_cast<unsigned int>(time(0)));
    int random_number = rand() % 256;
    return "6.6.6." + std::to_string(random_number);
    
    
}

// Génère un nouveau port public
int nat::get_new_public_port() {
    // Code de génération d'un port public
    // Par exemple, vous pouvez générer un port aléatoire dans une plage de ports spécifique ou utiliser une logique personnalisée pour attribuer des ports disponibles
    // Dans cet exemple, nous retournerons un port aléatoire entre 1024 et 65535
 srand(static_cast<unsigned int>(time(0)));
    return rand() % 64512 + 1024;
    
}
   
   
   
   
   
   packet nat::nat_bidirectionnel(packet packet) {



    std::string src_ip = packet.src_ip;
    int src_port = packet.src_port;
    std::string dst_ip = packet.dst_ip;
    int dst_port = packet.dst_port;
        if(packet.entre==true){
    // Vérifier si la traduction de l'adresse et du port existe déjà
   /* auto it = std::find_if(nat_translation.begin(), nat_translation.end(),
                           [&](const Translation& t) {
                               return t.original_ip == src_ip && t.original_port == src_port;
                           });*/

        Translation it;
        for(Translation tt : nat_translation){
            if(tt.original_ip == src_ip && tt.original_port == src_port){it.translated_ip=tt.translated_ip;it.translated_port=tt.translated_port; // Connexion sortante : traduire l'adresse IP et le port source
        packet.src_ip = it.translated_ip;
        packet.src_port = it.translated_port;
        return packet;}
        }
    /*if (it != nat_translation.end()) {
        // Connexion sortante : traduire l'adresse IP et le port source
        packet.src_ip = it.translated_ip;
        packet.src_port = it.translated_port;
        return packet;
    }*/
    
        // Nouvelle connexion sortante : créer une nouvelle traduction d'adresse et de port
        std::string translated_src_ip = get_new_public_ip();
      //  cout<<endl<<translated_src_ip<<" ";
        int translated_src_port = get_new_public_port();
        //cout<<endl<<translated_src_port<<" ";
        nat_translation.push_back({src_ip, src_port, translated_src_ip, translated_src_port});
        packet.src_ip = translated_src_ip;
        packet.src_port = translated_src_port;
        return packet;
    
        }else{
    // Connexion entrante : traduire l'adresse IP et le port de destination
    auto it2 = std::find_if(nat_translation.begin(), nat_translation.end(),
                            [&](const Translation& t) {
                                return t.translated_ip == dst_ip && t.translated_port == dst_port;
                            });

    if (it2 != nat_translation.end()) {
        packet.dst_ip = it2->original_ip;
        packet.dst_port = it2->original_port;
    }
    return packet;
        }
}

