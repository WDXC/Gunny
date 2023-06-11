#ifndef _GUNNY_GAME_H_
#define _GUNNY_GAME_H_

#include <SDL.h>
#include <memory>

#include "AssetManager.h"
#include "SceneManager.h"

namespace Gunny {
class Game {
public:
    /**
     * @Synopsis Create Game 
     *
     * @Param windowName
     * @Param windowWidth
     * @Param windowHeight
     */
  Game(const std::string &windowName, const int windowWidth,
       const int windowHeight);
  /**
   * @Synopsis  Destory game
   */
  ~Game();
  /**
   * @Synopsis  run game loop
   */
  void run();
  /**
   * @Synopsis  Stop game loop
   */
  void stop();
  /**
   * @Synopsis  Get the window width
   *
   * @Returns  int - window width
   */
  int getWindowWidth() const;
  /**
   * @Synopsis  Get the window height
   *
   * @Returns  int - window height 
   */
  int getWindowHeight() const;
  /**
   * @Synopsis  Get SDL2 Renderer
   *
   * @Returns   SDL_Renderer* - SDL2 renderer
   */
  SDL_Renderer *getRenderer() const;
  /**
   * @Synopsis  Get Scene Manager reference
   *
   * @Returns   SceneManager* - scene manager reference
   */
  SceneManager *getSceneManager() const;
  /**
   * @Synopsis  Get asset manager reference
   *
   * @Returns   AssetManager* - asset manager reference
   */
  AssetManager *getAssetManager() const;

private:
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  SceneManager *sceneManager = nullptr;
  AssetManager *assetManager = nullptr;

  int windowWidth = 0;
  int windowHeight = 0;

  bool isRunning = false;
  Uint32 lastTickTime = 0;
};
} // namespace Gunny

#endif
