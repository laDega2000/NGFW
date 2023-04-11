#ifndef LOG_H
#define LOG_H

#include <string>
#include <fstream>



class Log {
public:
    Log();
    ~Log();
    void writeLog(std::string type, const std::string& message);
    


    std::ofstream logFile;
};

#endif // LOG_H
