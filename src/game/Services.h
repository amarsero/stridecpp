#pragma once
#include "ScriptSystem.h"
#include "SceneSystem.h"
#include "AudioSystem.h"
#include "DebugTextSystem.h"
#include "GameProfilingSystem.h"
#include "GraphicsDeviceManager.h"
class Services
{
public:
  const ScriptSystem ScriptSystem{};
  const SceneSystem SceneSystem{};
  const AudioSystem AudioSystem{};
  const DebugTextSystem DebugTextSystem{};
  const GameProfilingSystem GameProfilingSystem{};
  const GraphicsDeviceManager GraphicsDeviceManager{};
};
