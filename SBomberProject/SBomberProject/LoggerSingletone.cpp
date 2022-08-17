#include "LoggerSingletone.h"
#include "FileLogger.h"

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
	static int firstStringNum = 1;
	if (FileLoggerSingletone::getInstance().logOut.is_open())
	{
		FileLoggerSingletone::getInstance().logOut << to_string(firstStringNum++) << " ";
	}
}
