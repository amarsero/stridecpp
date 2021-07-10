#include "GlobalLogger.h"

GlobalLogger* GlobalLogger::GetLogger(Modules module)
{
	return GetLogger(module, MinimumLevelEnabled);
}

GlobalLogger* GlobalLogger::GetLogger(Modules module, LogMessageType minimumLevel)
{
	GlobalLogger *logger;
	{
		std::lock_guard<std::mutex> guard(MapModuleToLoggerMutex);
		logger = MapModuleToLogger[(int)module];
		if (logger == nullptr) {
			logger = new GlobalLogger(module);
			logger->ActivateLog(minimumLevel);
			MapModuleToLogger[(int)module] = logger;
		}
	}
	return logger;
}

void GlobalLogger::ActivateLog(LogMessageType fromLevel, LogMessageType toLevel, bool enabledFlag)
{
	// From lower to higher, so we keep fromLevel < toLevel
	if (fromLevel > toLevel) {
		LogMessageType temp = fromLevel;
		fromLevel = toLevel;
		toLevel	  = temp;
	}

	for (size_t i = (size_t)fromLevel; i <= (size_t)toLevel; i++)
		EnableTypes[i] = true;
}

GlobalLogger::GlobalLogger(Modules module)
{
	Module = module;
}

void GlobalLogger::Log(ILogMessage logMessage)
{

}
