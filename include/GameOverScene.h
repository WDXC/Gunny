#ifndef _GUNNY_SCENES_GAME_OVER_SCENE_H_
#define _GUNNY_SCENES_GAME_OVER_SCENE_H_

#include <SDL.h>
#include <memory>

#include "Text.h"
#include "Scene.h"

namespace Gunny
{
    /**
     * @brief Game Over Scene
     *
     */
    class GameOverScene : public Scene
    {
      public:
        /**
         * @brief Construct a new Game Over Scene
         *
         * @param game
         */
        GameOverScene(Game* game);
        /**
         * @brief Trigger on update if scene is active
         *
         * @param delta - time in milliseconds
         */
        virtual void update(const unsigned int delta) override;

      private:
        // timer until switch to next menu
        int untilNextSceneTimer = 0;
        // const
        const int sceneTimer = 2000;
    };
} 

#endif 
