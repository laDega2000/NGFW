#ifndef STRATEGIE_RTG_H
#define STRATEGIE_RTG_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"
#include "tabdomain.h"
#include "inter_conf.h"
#include "packet.h"
class strategieRTG {
public:
    virtual std::string route(packet pac,inter_conf* r,inter_conf* t)=0;
};

#endif // STRATEGIE_RTG_H
