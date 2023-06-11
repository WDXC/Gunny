#ifndef _GNUUY_ENEMY_H_
#define _GNUUY_ENEMY_H_

#include "Creature.h"
#include <utility>

namespace Gunny {
enum class AIType : int { Wandering, Chasing };

class Enemy : public Creature {
public:
    /**
     * @Synopsis  Create enemy
     *
     * @Param texture
     * @Param renderer
     */
  Enemy(std::shared_ptr<SDL_Texture> texture, SDL_Renderer *renderer);
  /**
   * @Synopsis  Move enemy to specified position
   *
   * @Param x
   * @Param y
   */
  void moveTo(const int x, const int y);
  void moveToCell(std::pair<int, int> pathToCell);
  /**
   * @Synopsis  Return is enemy moving to cell or not
   *
   * @Returns   
   */
  bool isMovingToCell() const;
  /**
   * @Synopsis  Can enemy attack
   *
   * @Returns   
   */
  bool canAttack() const;
  /**
   * @Synopsis  get attack Radius of enemy
   *
   * @Returns   
   */
  int getAttackRadius() const;
  /**
   * @Synopsis  set Ai Type
   *
   * @Param type
   */
  void setAIType(AIType type);
  /**
   * @Synopsis  update movement of enemy
   *
   * @Param delta
   */
  virtual void update(const unsigned int delta) override;
  /**
   * @Synopsis  Generate new path if enemy finish movement
   */
  void generateNewPath();

private:
  /**
   * @Synopsis  update movement of enemy
   *
   * @Param delta
   */
  void updateMovement(const unsigned int delta);

  int newPositionX = 0;
  int newPositionY = 0;
  bool movingToCell = false;
  std::pair<int, int> path;
  // AI
  AIType aiType = AIType::Wandering;

  const float baseSpeed = 0.0018f;
  const float attackSpeed = 0.0025f;
  const int attackRadius = 4;

  std::shared_ptr<Animation> movement;
};
} // namespace Gunny

#endif
