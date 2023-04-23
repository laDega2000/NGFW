#ifndef STRATEGIE_SEC_H
#define STRATEGIE_SEC_H

#include <string>
#include "Policy.h"
#include "session.h"
#include "tabses.h"
#include "tabdomain.h"
#include "configuration.h"
#include "packet.h"
class strategieSEC {
public:
    virtual bool execute( packet pac,inter_conf* p, tabses& s,tabdomain& tab)=0;
};

#endif // STRATEGIE_SEC_H
