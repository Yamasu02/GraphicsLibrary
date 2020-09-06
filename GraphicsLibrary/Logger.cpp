#include "Logger.h"

Logger::Logger(bool fromStart, bool DeleteOld)
{
	DeleteOld ? file.open("C:\\menu.txt", std::fstream::in | std::fstream::out | std::fstream::trunc) : file.open("C:\\menu.txt", std::fstream::in | std::fstream::out);
}

void Logger::ReadLine(std::string& str, int index)
{
	if (file.is_open())
	{
		PutCursorStart();
		for (int x = 0; x <= index; x++)
		{
			std::getline(file, str);
		}
	}
}

void Logger::WriteLine(const std::string str, bool fromStart)
{
	if (file.is_open())
	{
		if (fromStart)
		{
			PutCursorStart();
		}
		file << str.c_str() << std::endl;
	}
}

bool Logger::compareString(std::string str2Compare1, std::string str2Compare2)
{
	return !str2Compare1.compare(str2Compare2);
}

bool Logger::IsFeatureOn(std::string feature)
{
	std::string CurrFeature;
	int i = 0;
	while (!ReachedEnd())
	{
		ReadLine(CurrFeature, i);
		if (CurrFeature.find(feature) != std::string::npos)
		{
			std::reverse(CurrFeature.begin(), CurrFeature.end());

			if (CurrFeature[0] == '1')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		++i;
	}
}

bool Logger::PutCursorStart()
{
	file.seekg(std::ios::beg);
	return file.good();
}

bool Logger::ReachedEnd()
{
	return file.eof();
}

bool Logger::PutCursorEnd()
{
	file.seekg(std::ios::end);
	return file.good();
}

bool Logger::PutCursorRelativeStart(int index)
{
	file.seekg(index, std::ios::end);
	return file.good();
}

bool Logger::PutCursorRelativeEnd(int index)
{
	file.seekg(index, std::ios::end);
	return file.good();
}

Logger::~Logger()
{
	file.close();
}