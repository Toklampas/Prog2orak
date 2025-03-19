#include "logging.h"

using namespace logging;

Logger::Logger()
{}

Logger::Logger(const Logger& theOther)
{}

Logger& Logger::getInstance()
{
	static Logger theLogger; //statikus, tehat egy peldany fog belole letezni
	return theLogger;
}

void logging::Logger::setDefaultLogLevel(const LogLevel&)
{
}

void logging::Logger::log(LogLevel, const char*)
{
}
