#ifndef _GUNNY_ANIMATION_H_
#define _GUNNY_ANIMATION_H_

#include <vector>
namespace Gunny {
class Sprite;

struct AnimationEntity {
  /**
   * @Synopsis  construct a new Animation Entity object
   *
   * @Param posX
   * @Param posY
   * @Param w
   * @Param h
   */
  AnimationEntity(const unsigned int posX, const unsigned int posY,
                  const unsigned int w, const unsigned int h)
      : positionX(posX), positionY(posY), width(w), height(h) {}
  unsigned int positionX = 0;
  unsigned int positionY = 0;
  unsigned int width = 0;
  unsigned int height = 0;
};

class Animation {
public:
    /**
     * @Synopsis  add entity
     *
     * @Param entity
     */
  void addAnimationEntity(AnimationEntity entity);
  /**
   * @Synopsis  set the sprite ot animation for clipping
   *
   * @Param sprite
   */
  void setSprite(Sprite *sprite);
  /**
   * @Synopsis  set the animation Interval to change clipping
   *
   * @Param timeInMs
   */
  void setAnimationInterval(const unsigned int timeInMs);
  /**
   * @Synopsis  play animation
   */
  void play();
  /**
   * @Synopsis  pause animation
   */
  void pause();
  /**
   * @Synopsis  reset animation and pause
   */
  void reset();
  /**
   * @Synopsis  update animation
   *
   * @Param delta
   */
  void update(const unsigned int delta);

private:
  std::vector<AnimationEntity> animation;
  unsigned int interval = 100;
  unsigned int time = 0;
  bool isPlaying = false;
  unsigned int currentEntity = 0;
  Sprite *sprite = nullptr;
};
} // namespace Gunny

#endif
