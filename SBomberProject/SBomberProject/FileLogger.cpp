#include "MyTools.h"
#include "FileLogger.h"

using namespace std;
using namespace MyTools;

void __fastcall FileLoggerSingletone::OpenLogFile(const string& FN)
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