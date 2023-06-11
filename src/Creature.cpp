#include "Creature.h"

namespace Gunny {
    void Creature::revertLastMove() {
        setPosition(getPositionX() - prevPosDeltaX, getPositionY() - prevPosDeltaY);
    }

    void Creature::setMoving(bool _moving)
    {
        this->moving = _moving;
    }

    bool Creature::isMoving() const 
    {
        return moving;
    }
}
