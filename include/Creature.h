#ifndef _GUNNY_CREATURE_H_
#define _GUNNY_CREATURE_H_

#include "Sprite.h"

namespace Gunny {
class Creature : public Sprite {
public:
    /**
     * @Synopsis  create creature
     */
  using Sprite::Sprite;
  /**
   * @Synopsis  Revert last movement of creature
   */
  void revertLastMove();
  /**
   * @Synopsis  set creature to move
   *
   * @Param isMoving
   */
  void setMoving(bool isMoving);
  /**
   * @Synopsis  Is Creature moving at this moment
   *
   * @Returns   true - if moving
   * @Returns   false - if idle
   */
  bool isMoving() const;

protected:
  int prevPosDeltaX = 0;
  int prevPosDeltaY = 0;

private:
  bool moving = false;
};
} // namespace Gunny

#endif
