#include "session.h"

session::session(std::string src_ip, std::string dst_ip, int src_port, int dst_port, std::string state) {
    this->src_port = src_port;
    this->dst_port = dst_port;
    this->state = state;
    this->src_ip = src_ip;
    this->dst_ip = dst_ip;
}

session::session(){
    
}