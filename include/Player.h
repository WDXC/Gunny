#ifndef _GUNNY_PLAYER_H_
#define _GUNNY_PLAYER_H_

#include "Animation.h"
#include "Creature.h"

namespace Gunny {
enum class MovementDirection { None, Up, Down, Left, Right };

class Player : public Creature {
public:
    /**
     * @Synopsis  Create player
     *
     * @Param texture
     * @Param renderer
     */
  Player(std::shared_ptr<SDL_Texture> texture, SDL_Renderer *renderer);
  /**
   * @Synopsis  Set movement and animation of player
   *
   * @Param direction
   */
  void setMovementDirection(MovementDirection direction);
  /**
   * @Synopsis  update movement and animation of player
   *
   * @Param delta - time in milliseconds
   */
  virtual void update(const unsigned int delta) override;

private:
  /**
   * @Synopsis  Is movement directoion by Y
   *
   * @Returns   
   */
  bool isMovingVertically() const;
  /**
   * @Synopsis  Is movement direction by X
   *
   * @Returns   
   */
  bool isMovingHorizontally() const;
  MovementDirection movementDirection = MovementDirection::None;

  const float speed = 0.004f;
  std::shared_ptr<Animation> movement;
};
} // namespace Gunny

#endif
