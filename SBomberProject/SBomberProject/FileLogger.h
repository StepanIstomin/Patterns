#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileLoggerSingletone
{
public:
    static FileLoggerSingletone& getInstance() {
        static FileLoggerSingletone theInstance;
        return theInstance;
    };
    void __fastcall OpenLogFile(const string& FN);
    void CloseLogFile();
    void __fastcall WriteToLog(const string& str);
    void __fastcall WriteToLog(const string& str, int n);
    void __fastcall WriteToLog(const string& str, double d);
private:
    FileLoggerSingletone() {};
    FileLoggerSingletone(const FileLoggerSingletone& root) = delete;
    FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
    ofstream logOut;
};