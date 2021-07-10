#pragma once
#include "LogMessageType.h"
#include "ILogListener.h"
#include "ILogMessage.h"
class ConsoleLogListener : public ILogListener
{
  void OnLog(ILogMessage logMessage);
};
