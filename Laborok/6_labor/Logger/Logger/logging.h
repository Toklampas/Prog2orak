#pragma once

namespace logging
{
	typedef enum { DEBUG, INFO, WARN, ERROR } LogLevel; //es meg mi lehet?

	class Logger
	{
		Logger(); //privat konstruktorok!
		Logger(const Logger&);

		LogLevel defaultLogLevel;
	public:
		static Logger& getInstance(); //ez vissza kell hogy adjon egy statikus peldanyt

		void setDefaultLogLevel(const LogLevel&);
		void log(LogLevel, const char*);
	};
}
