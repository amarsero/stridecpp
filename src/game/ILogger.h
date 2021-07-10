#pragma once
#include "ILogMessage.h"

/// <summary>
/// Interface for logging.
/// </summary>
class ILogger
{
  public:
	/// <summary>
	/// Gets the module this logger refers to.
	/// </summary>
	/// <value>The module.</value>
	Modules Module;
	/// <summary>
	/// Logs the specified log message.
	/// </summary>
	/// <param name="logMessage">The log message.</param>
	void virtual Log(ILogMessage logMessage) = 0;
};