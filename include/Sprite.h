#ifndef _GUNNY_SPRITE_H_
#define _GUNNY_SPRITE_H_

#include <SDL.h>
#include <memory>
#include <vector>

#include "Animation.h"
#include "Object.h"

namespace Gunny {
class Sprite : public Object {
public:
    /**
     * @Synopsis  Construct a new sprite object
     *
     * @Param texture
     * @Param renderer
     */
  Sprite(std::shared_ptr<SDL_Texture> texture, SDL_Renderer *renderer);
  /**
   * @Synopsis  Add animation to sprite
   *
   * @Param animation
   */
  void addAnimation(std::shared_ptr<Animation> animation);
  /**
   * @Synopsis  Node update
   *
   * @Param delta
   */
  virtual void update(const unsigned int delta) override;

private:
  std::vector<std::shared_ptr<Animation>> animations;
};
} // namespace Gunny

#endif
