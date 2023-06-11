#ifndef _GUNNY_SCENE_H_
#define _GUNNY_SCENE_H_

#include <SDL.h>
#include <vector>

#include "Object.h"

namespace Gunny {
class Game;

class Scene {
public:
  Scene(Game *game);
  virtual ~Scene();
  void addObject(std::shared_ptr<Object> object);
  void insertObject(std::shared_ptr<Object> object, int position);
  void removeObject(std::shared_ptr<Object>);
  void setCamera(const int x, const int y);
  virtual void onEnter();
  virtual void onExit();
  virtual void onEvent(const SDL_Event &event);
  virtual void update(const unsigned int delta);
  void draw() const;

protected:
  Game *game = nullptr;

private:
  std::vector<std::shared_ptr<Object>> objects;
  SDL_Rect camera;
};
} // namespace Gunny

#endif
