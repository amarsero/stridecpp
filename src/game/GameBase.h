#pragma once
#include "GameContext.h"
#include "GlobalLogger.h"
#include "ILogger.h"
class GameBase
{
public:
  bool IsRunning;
  Modules Module = Modules::Default;
	void Run(GameContext context);
  GameBase();

  //protected
  const ILogger* Log;
};
