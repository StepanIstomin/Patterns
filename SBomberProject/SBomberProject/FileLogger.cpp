#include "MyTools.h"
#include "FileLogger.h"

using namespace std;
using namespace MyTools;

// FileLoggerSingletone

void __fastcall FileLoggerSingletone::OpenLogFile (const string& FN)
{
    logOut.open(FN, ios_base::out);
}

void FileLoggerSingletone::CloseLogFile()
{
    if (logOut.is_open())
    {
        logOut.close();
    }
}
void __fastcall FileLoggerSingletone::WriteToLog(const string& str)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << std::endl;
    }
}

void __fastcall FileLoggerSingletone::WriteToLog(const string& str, int n)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << n << endl;
    }
}

void __fastcall FileLoggerSingletone::WriteToLog(const string& str, double d)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << d << endl;
    }
}

// LoggerSingletone

void __fastcall LoggerSingletone::WriteToLog(const string& str)
{
    stringNumWrite();
    FileLoggerSingletone::getInstance().WriteToLog(str);
}

void __fastcall LoggerSingletone::WriteToLog(const string& str, int n)
{
    stringNumWrite();
    FileLoggerSingletone::getInstance().WriteToLog(str, n);
}

void __fastcall LoggerSingletone::WriteToLog(const string& str, double d)
{
    stringNumWrite();
    FileLoggerSingletone::getInstance().WriteToLog(str, d);
}

void LoggerSingletone::stringNumWrite()
{
    if (FileLoggerSingletone::getInstance().logOut.is_open())
    {
        FileLoggerSingletone::getInstance().logOut << to_string(firstStringNum++) << " ";
    }
}
