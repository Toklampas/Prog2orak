#include "logging.h"
#include <iostream>

using namespace logging;
using namespace std;

Logger::Logger() : defaultLogLevel(DEBUG)
{}

Logger::Logger(const Logger& theOther) : defaultLogLevel(theOther.defaultLogLevel)
{}

Logger& Logger::getInstance()
{
	static Logger theLogger; //statikus, tehat egy peldany fog belole letezni
	return theLogger;
}

void Logger::setDefaultLogLevel(const LogLevel& level)
{
	defaultLogLevel = level;
}

void Logger::log(LogLevel level, const char* str)
{
	string logLevelStr;
	logLevelStr = (level == DEBUG) ? "DEBUG" : (level == INFO) ? "INFO" : (level == WARN) ? "WARN" : "ERROR";
	switch (defaultLogLevel)
	{
	case DEBUG:
		std::cout << logLevelStr << ": " << str << std::endl;
		break;
	case INFO:
		if (level != DEBUG)
			std::cout << logLevelStr << ": " << str << std::endl;
		break;
	case WARN:
		if (level == WARN || level == ERROR)
			std::cout << logLevelStr << ": " << str << std::endl;
		break;
	case ERROR:
		if (level == ERROR)
			std::cout << logLevelStr << ": " << str << std::endl;
		break;
	}
}
