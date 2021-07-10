#include "Game.h"
#include "ConsoleLogListener.h"
Game::Game(){
    GlobalLogger::GlobalMessageLogged.connect(&ILogListener::OnLog, &logListener);
}