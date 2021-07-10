#pragma once
#include "StreamingManager.h"
#include "GameBase.h"
class Game : public GameBase
{
public:

private:
  GlobalLogger *Logger;
  StreamingManager StreamingManager;
};
