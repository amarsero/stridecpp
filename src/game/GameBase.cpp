#include "GameBase.h"
#include "Services.h"

void GameBase::Run(GameContext context)
{
	if (IsRunning) {
		throw "Cannot run this instance while it is already running";
	}
	if (&context) {

	}
}

  GameBase::GameBase()
  {
	  Log = GlobalLogger::GetLogger(Module);
  }
