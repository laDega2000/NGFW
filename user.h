#ifndef USER_H
#define USER_H
#include <string>
#include "zone.h"
enum user_level {
    admin,
    guest,
    regular,
};

enum user_state {
    online,
    offline,
    blocked,
};
class user
{

public:
    int id;
    std::string name;
    user_level lev;
    user_state sat;
    std::string ip_adr;
    std::string mac;
    zone zonn;
    std::string group;
    user();


};
#endif