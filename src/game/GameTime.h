#pragma once
#include <chrono>
class GameTime
{
private:
  std::chrono::nanoseconds accumulatedElapsedTime{0};
  int accumulatedFrameCountPerSecond;
  double factor;
  std::chrono::nanoseconds total{0};
  std::chrono::nanoseconds elapsed{0};
  int frameCount;
  float framesPerSecond;
  float timePerFrame;
  bool framePerSecondUpdated;
  std::chrono::nanoseconds warpElapsed{0};

public:
  /// <summary>
  /// Initializes a new instance of the <see cref="GameTime" /> class.
  /// </summary>
  GameTime()
  {
    accumulatedElapsedTime = accumulatedElapsedTime.zero();
    factor = 1;
  }

  /// <summary>
  /// Initializes a new instance of the <see cref="GameTime" /> class.
  /// </summary>
  /// <param name="totalTime">The total game time since the start of the game.</param>
  /// <param name="elapsedTime">The elapsed game time since the last update.</param>
  GameTime(std::chrono::nanoseconds totalTime, std::chrono::nanoseconds elapsedTime)
  {
    total = totalTime;
    elapsed = elapsedTime;
    accumulatedElapsedTime = accumulatedElapsedTime.zero();
    factor = 1;
  }

  /// <summary>
  /// Gets the elapsed game time since the last update
  /// </summary>
  /// <value>The elapsed game time.</value>  
  std::chrono::nanoseconds Elapsed() {return elapsed;}
  /// <summary>
  /// Gets the amount of game time since the start of the game.
  /// </summary>
  /// <value>The total game time.</value>
  std::chrono::nanoseconds Total() {return total;}

  /// <summary>
  /// Gets the current frame count since the start of the game.
  /// </summary>
  int FrameCount() {return frameCount;}

  /// <summary>
  /// Gets the number of frame per second (FPS) for the current running game.
  /// </summary>
  /// <value>The frame per second.</value>
  float FramesPerSecond() {return framesPerSecond;}

  /// <summary>
  /// Gets the time per frame.
  /// </summary>
  /// <value>The time per frame.</value>
  float TimePerFrame() {return timePerFrame;}

  /// <summary>
  /// Gets a value indicating whether the <see cref="FramePerSecond"/> and <see cref="TimePerFrame"/> were updated for this frame.
  /// </summary>
  /// <value><c>true</c> if the <see cref="FramePerSecond"/> and <see cref="TimePerFrame"/> were updated for this frame; otherwise, <c>false</c>.</value>
  float FramePerSecondUpdated() {return framePerSecondUpdated;}

  /// <summary>
  /// Gets the amount of time elapsed multiplied by the time factor.
  /// </summary>
  /// <value>The warped elapsed time</value>
  std::chrono::nanoseconds WarpElapsed() {return warpElapsed;}


  /// <summary>
  /// Gets or sets the time factor.<br/>
  /// This value controls how much the warped time flows, this includes physics, animations and particles.
  /// A value between 0 and 1 will slow time, a value above 1 will make it faster.
  /// </summary>
  /// <value>The multiply factor, a double value higher or equal to 0</value>  
  float Factor() {return factor;}

  void Update(std::chrono::nanoseconds totalGameTime, std::chrono::nanoseconds elapsedGameTime, bool incrementFrameCount)
  {
    static constexpr std::chrono::duration<double> oneSecond{1};
    total = totalGameTime;
    elapsed = elapsedGameTime;
    warpElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed * factor);

    framePerSecondUpdated = false;

    if (incrementFrameCount) {
      accumulatedElapsedTime += elapsedGameTime;
      std::chrono::duration<double> accumulatedElapsedGameTimeInSecond = std::chrono::duration_cast<std::chrono::seconds>(accumulatedElapsedTime);
      if (accumulatedFrameCountPerSecond > 0 && accumulatedElapsedGameTimeInSecond > oneSecond) {
        std::chrono::nanoseconds TimePerFrame = accumulatedElapsedTime / accumulatedFrameCountPerSecond;
        float FramePerSecond = (float)(accumulatedFrameCountPerSecond / accumulatedElapsedGameTimeInSecond.count());
        accumulatedFrameCountPerSecond = 0;
        accumulatedElapsedTime = accumulatedElapsedTime.zero();
        framePerSecondUpdated = true;
      }

      accumulatedFrameCountPerSecond++;
      frameCount++;
    }
  }

  void Reset(std::chrono::nanoseconds totalGameTime)
  {
    Update(totalGameTime, accumulatedElapsedTime.zero(), false);
    accumulatedElapsedTime = accumulatedElapsedTime.zero();
    accumulatedFrameCountPerSecond = 0;
    frameCount = 0;
  }
  void ResetTimeFactor()
  {
    factor = 1;
  }
};