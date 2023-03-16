#include "Log.h"
#include <chrono>
#include <ctime>

Log::Log() {}

Log::~Log() {
    logFile.close();
}

void Log::writeLog(std::string type, const std::string& message) {
    // Obtenir la date et l'heure actuelles
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    

    // Écrire le message dans le fichier journal
    logFile.open("logs.log", std::ios::app);
    logFile << std::ctime(&currentTime) << " [" << type << "] " << message << std::endl;
    logFile.close();
}


