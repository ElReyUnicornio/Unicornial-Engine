//
// Created by tto415 on 11/10/26.
//

#ifndef UNICORNIALENGINE_LOGGER_H
#define UNICORNIALENGINE_LOGGER_H
#include <string>
#include <ctime>

enum LEVEL {
    info = 0,
    warning = 1,
    error = 2,
};

class Logger {
private:
    static std::string format(LEVEL l, const std::string& msg) {
        time_t timestamp;
        time(&timestamp);
        std::string prefix;
        switch (l) {
            case LEVEL::info:
                prefix = "[INFO] ";
                break;
            case LEVEL::warning:
                prefix = "[WARNING] ";
                break;
            case LEVEL::error:
                prefix = "[ERROR] ";
                break;
        }

        return ctime(&timestamp) + prefix + ": [" + msg + "] ";
    }
    public:
    static void log(const std::string &message) {
        printf("%s\n", this->format(LEVEL::info, message).c_str());
    }
    static void warn(const std::string &message) {
        printf("%s\n", this->format(LEVEL::warning, message).c_str());
    }
    static void error(const std::string &message) {
        printf("%s\n", this->format(LEVEL::error, message).c_str());
    }
};

#endif //UNICORNIALENGINE_LOGGER_H
