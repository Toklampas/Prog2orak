#include "logging.h"

using namespace logging;

int main()
{
	Logger& logger = Logger::getInstance();
	logger.setDefaultLogLevel(WARN);

	Logger& logger2 = Logger::getInstance(); //4. feladat: ez ugyanazt az objektumot adja vissza, mint a logger

	logger.log(INFO, "Network connection established.");
	logger.log(DEBUG, "Module A can communicate with remote host R.");
	logger.log(WARN, "Network card junction temperature is getting higher and higher.");
	logger.log(ERROR, "Network connection interrupted.");

	logger2.log(INFO, "Network connection established.");
	logger2.log(DEBUG, "Module A can communicate with remote host R.");
	logger2.log(WARN, "Network card junction temperature is getting higher and higher.");
	logger2.log(ERROR, "Network connection interrupted.");

	return 0;
}