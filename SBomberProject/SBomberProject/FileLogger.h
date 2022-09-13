#pragma once

#include <iostream>
#include <fstream>

class FileLogger
{
public:
	FileLogger() { OpenLogFile("log.txt"); };
	~FileLogger() { CloseLogFile(); }

	void __fastcall OpenLogFile(const std::string& FN);

	void CloseLogFile();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);

private:
	std::ofstream logOut;
};

