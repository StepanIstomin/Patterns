#pragma once

#include <string>

#include "FileLogger.h"

using namespace std;

class LoggerSingletone
{
public:
    static LoggerSingletone& getInstance() {
        static LoggerSingletone theInstance;
        return theInstance;
    };
    void __fastcall WriteToLog(const string& str);
    void __fastcall WriteToLog(const string& str, int n);
    void __fastcall WriteToLog(const string& str, double d);
private:
    LoggerSingletone() {};
    LoggerSingletone(const LoggerSingletone& root) = delete;
    LoggerSingletone& operator=(const LoggerSingletone&) = delete;
    void stringNumWrite();
};

