#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <string>


class Logger
{
private:

	std::fstream file;

public:

	Logger(bool fromStart = true, bool DeleteOld = false);


	void ReadLine(std::string& str, int index);


	void WriteLine(const std::string str, bool fromStart);


	bool compareString(std::string str2Compare1, std::string str2Compare2);


	bool IsFeatureOn(std::string feature);


	bool PutCursorStart();


	bool ReachedEnd();


	bool PutCursorEnd();


	bool PutCursorRelativeStart(int index);


	bool PutCursorRelativeEnd(int index);


	~Logger();
};