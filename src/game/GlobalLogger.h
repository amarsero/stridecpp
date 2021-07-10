#pragma once
#include "LogMessageType.h"
#include "ILogger.h"
#include "ModulesEnum.h"
#include "libs/signal.hpp"
#include <utility>
#include <mutex>
#include <vector>

class GlobalLogger : public ILogger
{
  public:
	static GlobalLogger *MapModuleToLogger[(unsigned long long)Modules::LENGTH];
	static std::mutex MapModuleToLoggerMutex;
	static const LogMessageType MinimumLevelEnabled{ LogMessageType::Info };
	/// <summary>
	/// Gets the <see cref="GlobalLogger"/> associated to the specified module.
	/// </summary>
	/// <param name="module">The module name.</param>
	/// <exception cref="ArgumentNullException">If module name is null</exception>
	/// <returns>An instance of a <see cref="Logger"/></returns>
	static GlobalLogger *GetLogger(Modules module);
	/// <summary>
	/// Gets the <see cref="GlobalLogger"/> associated to the specified module.
	/// </summary>
	/// <param name="module">The module name.</param>
	/// <param name="minimumLevel">Minimum log level (only applied if new logger instance is created)</param>
	/// <exception cref="ArgumentNullException">If module name is null</exception>
	/// <returns>An instance of a <see cref="Logger"/></returns>
	static GlobalLogger *GetLogger(Modules module, LogMessageType minimumLevel);
	/// <summary>
	/// Gets the module name. read-only.
	/// </summary>
	/// <value>The module name.</value>
	Modules Module;/// <summary>
	bool EnableTypes[(unsigned long long)LogMessageType::LENGTH];
	  /// Activates the log for this logger for a range of <see cref="LogMessageType"/>.
	  /// </summary>
	  /// <param name="fromLevel">The lowest inclusive level to log for.</param>
	  /// <param name="toLevel">The highest inclusive level to log for.</param>
	  /// <param name="enabledFlag">if set to <c>true</c> this will enable the log, false otherwise. Default is true.</param>
	  /// <remarks>
	  /// Outside the specified range the log message type are disabled (!enabledFlag).
	  /// </remarks>
	void ActivateLog(LogMessageType fromLevel, LogMessageType toLevel = LogMessageType::Fatal, bool enabledFlag = true);
	sigslot::signal<ILogMessage> GlobalMessageLogged;
	

  private:
	GlobalLogger(Modules module);
	static std::vector<ILogger *> onGlobalMessageLoggedCallbacks;
	static std::mutex MapModuleToLoggerMutex;

	// Inherited via ILogger
	virtual void Log(ILogMessage logMessage) override;
};