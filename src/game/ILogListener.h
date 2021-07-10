#pragma once
#include "ILogMessage.h"
class ILogListener
{
public: 
	void virtual OnLog(ILogMessage logMessage) = 0;
};
