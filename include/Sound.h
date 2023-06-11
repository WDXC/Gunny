#ifndef _GUNNY_SOUND_H_
#define _GUNNY_SOUND_H_

#include <SDL_mixer.h>
#include <memory>

namespace Gunny {
class Sound {
public:
  /**
   * @Synopsis  contruct a new sound object
   *
   * @Param sound
   */
  Sound(std::shared_ptr<Mix_Chunk> sound);
  /**
   * @Synopsis  start playing sound
   */
  void play();

private:
  std::shared_ptr<Mix_Chunk> sound = nullptr;
};
} // namespace Gunny

#endif
