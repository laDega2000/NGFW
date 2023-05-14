#include "filtrurl.h"
#include "url_conf.h"
filtrurl::filtrurl() {}





bool filtrurl::execute(packet pac, inter_conf* p, tabses& s,tabdomain& tab) {



    
        char* url = nullptr;
        // Chercher l'URL dans le header HTTP
        if (pac.header != nullptr) {
            char* start = strstr(pac.header, "Host: ");
            if (start != nullptr) {
                start += 6; // Avancer le pointeur pour passer le texte "Host: "
                char* end = strchr(start, '\r');
                if (end != nullptr) {
                    // Allouer une nouvelle chaîne de caractères pour stocker l'URL
                    size_t url_len = end - start;
                    url = new char[url_len + 1];
                    strncpy(url, start, url_len);
                    url[url_len] = '\0'; // Terminer la chaîne de caractères
                }
            }
        }
        // Chercher l'URL dans le payload HTTP
        if (pac.payload != nullptr) {
            char* start = strstr(pac.payload, "GET ");
            if (start != nullptr) {
                start += 4; // Avancer le pointeur pour passer le texte "GET "
                char* end = strchr(start, ' ');
                if (end != nullptr) {
                    // Allouer une nouvelle chaîne de caractères pour stocker l'URL
                    size_t url_len = end - start;
                    if (url == nullptr) {
                        url = new char[url_len + 1];
                        strncpy(url, start, url_len);
                        url[url_len] = '\0'; // Terminer la chaîne de caractères
                    } else {
                        // Concaténer l'URL avec celle trouvée dans le header
                        size_t old_len = strlen(url);
                        url = (char*) realloc(url, old_len + url_len + 1);
                        strncat(url, start, url_len);
                        url[old_len + url_len] = '\0'; // Terminer la chaîne de caractères
                    }
                }
            }
        }
        base bb;
        printf(url);
        p=new url_conf;
        if(p->get(url,bb).domaine==true)return false;
        else return true;
    


    /*tools t;
    Log m;
    tabdomain tabb;
    if (t.isDNSPacket(pac.)) {
      //  if (t.isQuery(packet)) {
            //printf("je suis dns");
            char* domainName = t.extractDomainName(packet);
            printf(domainName);
            // Faites quelque chose avec le nom de domaine ici
            if(tabb.is_domain(domainName)){
            printf("paquet rejeter");
            return false;
            }
            else{
                 printf("Paquet accepter : Nom de Domain  autoriser.\n");
                     std::string deg=domainName;
                      std::string s_log = "Packet Rejeter. Domain: " + deg+  ".";
                     m.writeLog("WARNIING", s_log);
                    return true;
                    
            }
            //delete[] domainName; // N'oubliez pas de libérer la mémoire allouée !
       // }
       // else return false;
    }else{
        printf("je ne suis pas dns"); 
        return false;
    }
*/
}