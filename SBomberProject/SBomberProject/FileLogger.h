#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Logger
{
public:
    virtual void __fastcall WriteToLog(const string& str) = 0;
    virtual void __fastcall WriteToLog(const string& str, int n) = 0;
    virtual void __fastcall WriteToLog(const string& str, double d) = 0;
};

class FileLoggerSingletone : public Logger
{
public:
    static FileLoggerSingletone& getInstance() {
        static FileLoggerSingletone theInstance;
        return theInstance;
    };
    void __fastcall OpenLogFile (const string& FN);
    void CloseLogFile();
    void __fastcall WriteToLog(const string& str);
    void __fastcall WriteToLog(const string& str, int n);
    void __fastcall WriteToLog(const string& str, double d);
    friend class LoggerSingletone;
private:
    FileLoggerSingletone() {};
    FileLoggerSingletone(const FileLoggerSingletone& root) = delete;
    FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
    ofstream logOut;
};

class LoggerSingletone : public Logger
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
    int firstStringNum = 1;
};