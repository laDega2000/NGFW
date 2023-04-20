#ifndef STRATEGIE_RTG_H
#define STRATEGIE_RTG_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"
#include "tabdomain.h"
#include "tab_route.h"
#include "tab_nat.h"
#include "packet.h"
class strategieRTG {
public:
    virtual std::string route(packet pac,tab_route r,tab_nat t)=0;
};

#endif // STRATEGIE_RTG_H
