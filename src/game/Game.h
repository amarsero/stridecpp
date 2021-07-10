#pragma once
#include "StreamingManager.h"
#include "GameBase.h"
class Game : public GameBase
{
public:
Game();
private:
  ConsoleLogListener logListener;
  GlobalLogger *Logger;
  StreamingManager StreamingManager;
};
