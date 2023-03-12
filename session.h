#ifndef SESSION_H
#define SESSION_H

#include <string>

class session {
public:
    std::string src_ip;
    std::string dst_ip;
    int src_port;
    int dst_port;
    std::string state;

    session(std::string src_ip, std::string dst_ip, int src_port, int dst_port, std::string state);
};

#endif
