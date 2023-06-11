#ifndef _GUNNY_MUSIC_H_
#define _GUNNY_MUSIC_H_

#include <SDL_mixer.h>
#include <memory>

namespace Gunny {
class Music {
public:
  /**
   * @Synopsis  contruct a new music object
   *
   * @Param music
   */
  Music(std::shared_ptr<Mix_Music> music);
  /**
   * @Synopsis  start playing music
   */
  void play();
  /**
   * @Synopsis  stop current music
   */
  void stop();
  /**
   * @Synopsis  pause music
   */
  void pause();
  /**
   * @Synopsis  resume music
   */
  void resume();

private:
  std::shared_ptr<Mix_Music> music = nullptr;
};
} // namespace Gunny

#endif
