#ifndef FILTRAGE_H
#define FILTRAGE_H
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/ether.h>
#include <pcap.h>
#include "strategieSEC.h"
#include "tabses.h"
#include "session.h"
#include "filtrage.h"
#include "monitoring.h"
#include "tabdomain.h"
class filtrage : public strategieSEC {
public:
    filtrage();
    strategieSEC* get_strategy();
    bool execute( packet pac, inter_conf* p, tabses& s,tabdomain& tab) override;
};

#endif // FILTRAGE_H
