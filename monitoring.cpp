#include "monitoring.h"
    monitoring::monitoring() {};

    void monitoring::set_log(std::string type,std::string msg){
        Log l;
        l.writeLog(type,msg);
    };


