#ifndef INTER_CONF_H
#define INTER_CONF_H
#include <string>
#include "Policy.h"
#include "base.h"
// Interface for CRUD operations
class inter_conf {
public:
    virtual void add() = 0; // Create operation
    virtual base get(std::string ss,base bo) = 0; // Read operation
    virtual void update(Rule rr,std::string nom) = 0; // Update operation
    //virtual void del() = 0; // Delete operation*/
};

#endif /* INTER_CONF_H */